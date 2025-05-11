#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "key_drv.h"


#define KEY1_SHORT_PRESS 0x01
#define KEY1_LONG_PRESS  0x81
#define KEY2_SHORT_PRESS 0x02
#define KEY2_LONG_PRESS  0x82
#define KEY3_SHORT_PRESS 0x03
#define KEY3_LONG_PRESS  0x83


void HmiTask(void)
{
	KeyScanProcess();
	uint8_t keyVal = GetKeyVal();
	switch (keyVal)
	{
		case KEY1_SHORT_PRESS:
			printf("key1 is short pressed!\n");
			break;
		case KEY1_LONG_PRESS:
			printf("key1 is long pressed!\n");
			break;
		case KEY2_SHORT_PRESS:
			printf("key2 is short pressed!\n");
			break;
		case KEY2_LONG_PRESS:
			printf("key2 is long pressed!\n");
			break;
		case KEY3_SHORT_PRESS:
			printf("key3 is short pressed!\n");
			break;
		case KEY3_LONG_PRESS:
			printf("key3 is long pressed!\n");
			break;
		default:
			break;
	}
}
