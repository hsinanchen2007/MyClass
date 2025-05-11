#ifndef _KEY_DRV_H_
#define _KEY_DRV_H_

#include <stdint.h>
#include <stdlib.h>


void KeyDrvInit(void);
void KeyScanProcess(void);
uint8_t GetKeyVal(void);

#endif
