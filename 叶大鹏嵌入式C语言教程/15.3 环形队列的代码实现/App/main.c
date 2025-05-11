#include <stdint.h>
#include <stdio.h>
#include "gd32f30x.h"
#include "led_drv.h"
#include "key_drv.h"
#include "systick.h"
#include "usb2com_drv.h"
#include "usb2com_app.h"
#include "delay.h"

static void DrvInit(void)
{
	SystickInit();
	LedDrvInit();
	KeyDrvInit();
	DelayInit();
	Usb2ComDrvInit();
}
static void AppInit(void)
{
	Usb2ComAppInit();
}

int main(void)
{	
	DrvInit();
	AppInit();

	while (1)
	{
		Usb2ComTask();
		DelayNms(500);
	}
}
