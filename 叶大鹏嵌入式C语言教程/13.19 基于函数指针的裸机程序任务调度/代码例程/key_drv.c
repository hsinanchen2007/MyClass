#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "gd32f30x.h"
#include "systick.h"


typedef struct
{
	rcu_periph_enum rcu;
	uint32_t gpio;
	uint32_t pin;
} Key_GPIO_t;

/* GPIO��PIN���� */
static const Key_GPIO_t g_gpioList[] = {
	{RCU_GPIOA, GPIOA, GPIO_PIN_0},			/* K1 */
	{RCU_GPIOG, GPIOG, GPIO_PIN_13},		/* K2 */
	{RCU_GPIOG, GPIOG, GPIO_PIN_14},		/* K3 */
};	

#define KEY_NUM_MAX (sizeof(g_gpioList) / sizeof(g_gpioList[0]))
	
typedef enum
{
    KEY_RELEASE = 0,
    KEY_COMFIRM,
    KEY_SHORTPRESS, 
	KEY_LONGPRESS
} KEY_STATE;

#define SHORT_PRESS_TIME     30       //  SINGLE_KEY_TIME*10MS = 30MS  �ж��̰���ʱ�䳤�ȣ��������
#define LONG_PRESS_TIME      1000     //  LONG_KEY_TIME*10MS   = 1S    �ж�������ʱ�䳤��

static uint8_t g_keyVal = 0;

typedef struct
{
	KEY_STATE keyState;
	uint64_t  prvTimeCount;
	uint64_t  curTimeCount;
} Key_Info_t;

static Key_Info_t keyInfo[KEY_NUM_MAX];

void KeyDrvInit(void)
{
	for (uint8_t i = 0; i < KEY_NUM_MAX; i++)
	{
		rcu_periph_clock_enable(g_gpioList[i].rcu); //ʹ��GPIO��ʱ��
		gpio_init(g_gpioList[i].gpio, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, g_gpioList[i].pin);
	}
}


static uint8_t KeyScan(uint8_t KeyIndex)
{

	uint8_t keyPress; 

    keyPress = gpio_input_bit_get(g_gpioList[KeyIndex].gpio, g_gpioList[KeyIndex].pin);
    switch (keyInfo[KeyIndex].keyState)     
    {       
        case KEY_RELEASE:                       //  �ͷ�״̬���ж����ް�������
            if (!keyPress)                     	//  �а�������
            {
                keyInfo[KeyIndex].prvTimeCount = GetSysTime();     //  ��ȡϵͳ����ʱ��
                keyInfo[KeyIndex].keyState = KEY_COMFIRM;          //  Ȼ����� ����״̬
            }        
            break;

        case KEY_COMFIRM:                       //  ����״̬
            if (!keyPress)                     
            {
                keyInfo[KeyIndex].curTimeCount = GetSysTime();                    //��ȡϵͳ����ʱ��
                if(keyInfo[KeyIndex].curTimeCount - keyInfo[KeyIndex].prvTimeCount >= SHORT_PRESS_TIME) 
                {
                    keyInfo[KeyIndex].keyState = KEY_SHORTPRESS;    //  �������ʱ�䳬������ʱ�䣬������Ϊ �̰�״̬
                }
            }         
            else
			{
				keyInfo[KeyIndex].keyState = KEY_RELEASE;       //  �������ʱ��û�г������ж�Ϊ��
			}

            break; 

        case KEY_SHORTPRESS:                       //  �̰�״̬�������ж������Ƕ̰������ǳ���
            if(keyPress)                           //  ��������� �趨�ĳ���ʱ�� ���ɿ������ж�Ϊ�̰�
            { 
                keyInfo[KeyIndex].keyState = KEY_RELEASE;       //  ���� �ͷ�״̬
				return (KeyIndex + 1);			  // ���ذ�����ֵ�����������̰���Ӧ0x01 02 03
            } 
            else
            {
                keyInfo[KeyIndex].curTimeCount = GetSysTime();                    //��ȡϵͳ����ʱ��
                if(keyInfo[KeyIndex].curTimeCount - keyInfo[KeyIndex].prvTimeCount >= LONG_PRESS_TIME)   //  �������ʱ�䳬�� �趨�ĳ���ʱ�䣬Ϊ����
                {
                    keyInfo[KeyIndex].keyState = KEY_LONGPRESS;      //  ���� ����״̬
                }
            }
            break;

      case KEY_LONGPRESS:                        
          if (keyPress) 
          {
              keyInfo[KeyIndex].keyState = KEY_RELEASE;          //  �����ɿ���,���� �ͷ�״̬��������һ�ΰ������ж�
			  return (0x80 + KeyIndex + 1);     // ���ذ�����ֵ����������������Ӧ0x81 82 83
          }        
          break; 

        default:                                
            keyInfo[KeyIndex].keyState = KEY_RELEASE;
            break;
    }

    return  0;                       
}

void KeyScanProcess(void)
{
	uint8_t res = 0;
	
	for (uint8_t i = 0; i < KEY_NUM_MAX; i++)
	{
		res = KeyScan(i);
		if (res != 0)
		{
			g_keyVal = res;
			break;
		}
		g_keyVal = 0;
	}
}


uint8_t GetKeyVal(void)
{
	return g_keyVal;
}