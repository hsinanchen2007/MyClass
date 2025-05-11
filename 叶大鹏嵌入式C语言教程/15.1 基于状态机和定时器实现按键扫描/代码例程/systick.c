#include "gd32f30x.h"
#include "systick.h"

static uint64_t g_sysRunTime = 0;        //系统运行时间（ms）

static void (*pTaskScheduleFunc)(void);

void SystickConfig(void)
{
    /* setup systick timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / 1000U)){
        /* capture error */
        while(1){
        }
    }
    /* configure the systick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}

void TaskScheduleCbReg(void (*pFunc)(void))
{
	pTaskScheduleFunc = pFunc;
}

void SysTick_Handler(void)
{
	g_sysRunTime++;         //系统运行时间加一
	pTaskScheduleFunc();
}

uint64_t GetSysTime(void)
{
  return g_sysRunTime;
}
