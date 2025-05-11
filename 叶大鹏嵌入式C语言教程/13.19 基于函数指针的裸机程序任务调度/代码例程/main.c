#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "gd32f30x.h"
#include "systick.h"
#include "hmi_app.h"
#include "uart_drv.h"

typedef struct 
{
	uint8_t run;                      	//����״̬��Run/Stop
	uint16_t TIMCount;         	//ʱ��Ƭ���ڣ����ڵݼ�����
	uint16_t TRITime;           	 //ʱ��Ƭ���ڣ���������
	void (*TaskFuncCb)(void); 	//����ָ�룬������������ַ
} TaskComps_t;     

 TaskComps_t TaskComps[] =
{
    //״̬  ����  ����  ����
	{0, 10, 10, HmiTask},		        /* task 2 Period�� 10ms */
	//{0, 10, 10, BoardTestTask},			/* task 1 Period�� 20ms*/
	/* Add new task here */
};

#define TASK_NUM_MAX (sizeof(TaskComps) / sizeof(TaskComps[0]))

void TaskScheduleCb(void)
{
	for (uint8_t i = 0; i < TASK_NUM_MAX; i++)
	{
		if (TaskComps[i].TIMCount)    /* �ж�ʱ��Ƭ���� */
		{
			TaskComps[i].TIMCount--;  /* ʱ��Ƭ�����ݼ� */
			if(TaskComps[i].TIMCount == 0)  
			{
				/*ʱ��Ƭ���Ϊ1�������ؼ�����ֵ */
				TaskComps[i].TIMCount = TaskComps[i].TRITime;  
				TaskComps[i].run = 1; 
			}
		}
	}
}

void TaskHandler(void)
{
	for (uint8_t i = 0; i < TASK_NUM_MAX; i++)
	{
		if(TaskComps[i].run) /* �ж�����ʱ��Ƭ��� */
		{
			TaskComps[i].run = 0;    /* ������� */
			TaskComps[i].TaskFuncCb();  /* ִ�е������� */
		}
	}
}


void HardwareInit(void)
{
	UartDrvInit(COM0, 115200);
	KeyDrvInit();
}
int main(void)
{      

    SystickConfig();
	HardwareInit();
	TaskScheduleCbReg(TaskScheduleCb);
	printf("key state test!\n");
	
    while (1)
	{
		
		TaskHandler();
    }
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}
