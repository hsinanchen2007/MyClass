#include <stdio.h>
#include "ARMCM4.h"   
#include "tem.h"
#include "co2.h"
#include "pm25.h"


struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;
 
int fputc(int ch, FILE *f) 
{
    return ITM_SendChar(ch);
}

volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;
int fgetc(FILE *f) 
{
    while(ITM_CheckChar() != 1)
	      __NOP();
    return (ITM_ReceiveChar());
}
int ferror(FILE *f) 
{
  /* Your implementation of ferror */
  return EOF;
}

void _ttywrch(int ch) 
{
	fputc(ch, &__stdout);
}

void _sys_exit(int return_code) 
{
  while (1);    /* endless loop */
}

float GetTemCofHmi(void)
{
	return 1.2f;
}

int main(void)
{
	volatile float celTem;
	
	SetTemCof(GetTemCofHmi());
	
	celTem = GetCelTem();
	printf("Temperature is %.1f cel degrees.\n", celTem);
	
	float fahTem = GetFahTem();
	printf("Temperature is %.1f fah degrees.\n", fahTem);
	
	QualityLevel co2Level;
	co2Level = GetCo2Level();
	DisplayCo2Level(co2Level);
	
	QualityLevel pm25Level;
	pm25Level = GetPm25Level();
	DisplayPm25Level(pm25Level);
	return 0;
}
