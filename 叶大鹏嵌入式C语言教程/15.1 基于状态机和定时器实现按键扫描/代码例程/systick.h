#ifndef _SYSTICK_H
#define _SYSTICK_H

#include <stdint.h>

void SystickConfig(void);
void TaskScheduleCbReg(void (*pFunc)(void));
uint64_t GetSysTime(void);
#endif /* _SYSTICK_H */
