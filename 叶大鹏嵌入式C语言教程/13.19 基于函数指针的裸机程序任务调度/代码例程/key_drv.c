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

/* GPIO和PIN定义 */
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

#define SHORT_PRESS_TIME     30       //  SINGLE_KEY_TIME*10MS = 30MS  判定短按的时间长度，软件消抖
#define LONG_PRESS_TIME      1000     //  LONG_KEY_TIME*10MS   = 1S    判定长按的时间长度

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
		rcu_periph_clock_enable(g_gpioList[i].rcu); //使能GPIO的时钟
		gpio_init(g_gpioList[i].gpio, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, g_gpioList[i].pin);
	}
}


static uint8_t KeyScan(uint8_t KeyIndex)
{

	uint8_t keyPress; 

    keyPress = gpio_input_bit_get(g_gpioList[KeyIndex].gpio, g_gpioList[KeyIndex].pin);
    switch (keyInfo[KeyIndex].keyState)     
    {       
        case KEY_RELEASE:                       //  释放状态：判断有无按键按下
            if (!keyPress)                     	//  有按键按下
            {
                keyInfo[KeyIndex].prvTimeCount = GetSysTime();     //  获取系统运行时间
                keyInfo[KeyIndex].keyState = KEY_COMFIRM;          //  然后进入 消抖状态
            }        
            break;

        case KEY_COMFIRM:                       //  消抖状态
            if (!keyPress)                     
            {
                keyInfo[KeyIndex].curTimeCount = GetSysTime();                    //获取系统运行时间
                if(keyInfo[KeyIndex].curTimeCount - keyInfo[KeyIndex].prvTimeCount >= SHORT_PRESS_TIME) 
                {
                    keyInfo[KeyIndex].keyState = KEY_SHORTPRESS;    //  如果按键时间超过消抖时间，先设置为 短按状态
                }
            }         
            else
			{
				keyInfo[KeyIndex].keyState = KEY_RELEASE;       //  如果按键时间没有超过，判定为误触
			}

            break; 

        case KEY_SHORTPRESS:                       //  短按状态：继续判定按键是短按，还是长按
            if(keyPress)                           //  如果按键在 设定的长按时间 内松开，则判定为短按
            { 
                keyInfo[KeyIndex].keyState = KEY_RELEASE;       //  设置 释放状态
				return (KeyIndex + 1);			  // 返回按键码值，三个按键短按对应0x01 02 03
            } 
            else
            {
                keyInfo[KeyIndex].curTimeCount = GetSysTime();                    //获取系统运行时间
                if(keyInfo[KeyIndex].curTimeCount - keyInfo[KeyIndex].prvTimeCount >= LONG_PRESS_TIME)   //  如果按键时间超过 设定的长按时间，为长按
                {
                    keyInfo[KeyIndex].keyState = KEY_LONGPRESS;      //  设置 长按状态
                }
            }
            break;

      case KEY_LONGPRESS:                        
          if (keyPress) 
          {
              keyInfo[KeyIndex].keyState = KEY_RELEASE;          //  按键松开后,设置 释放状态，进行下一次按键的判定
			  return (0x80 + KeyIndex + 1);     // 返回按键码值，三个按键长按对应0x81 82 83
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