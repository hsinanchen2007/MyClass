#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "gd32f30x.h"
#include "systick.h"
#include "hmi_app.h"
#include "uart_drv.h"

typedef struct 
{
	uint8_t run;                      	//任务状态：Run/Stop
	uint16_t TIMCount;         	//时间片周期，用于递减计数
	uint16_t TRITime;           	 //时间片周期，用于重载
	void (*TaskFuncCb)(void); 	//函数指针，保存任务函数地址
} TaskComps_t;     

 TaskComps_t TaskComps[] =
{
    //状态  计数  周期  函数
	{0, 10, 10, HmiTask},		        /* task 2 Period： 10ms */
	//{0, 10, 10, BoardTestTask},			/* task 1 Period： 20ms*/
	/* Add new task here */
};

#define TASK_NUM_MAX (sizeof(TaskComps) / sizeof(TaskComps[0]))

void TaskScheduleCb(void)
{
	for (uint8_t i = 0; i < TASK_NUM_MAX; i++)
	{
		if (TaskComps[i].TIMCount)    /* 判断时间片计数 */
		{
			TaskComps[i].TIMCount--;  /* 时间片计数递减 */
			if(TaskComps[i].TIMCount == 0)  
			{
				/*时间片标记为1，并重载计数初值 */
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
		if(TaskComps[i].run) /* 判断任务时间片标记 */
		{
			TaskComps[i].run = 0;    /* 标记清零 */
			TaskComps[i].TaskFuncCb();  /* 执行调度任务 */
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
