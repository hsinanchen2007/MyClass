#include <stdint.h>
#include <stdio.h>
#include "co2.h"

static int32_t GetRawData(void)
{
	return 500;
}

/*
小于100                                 对应           Excellent 0
大于等于100、小于200          对应           Good 1
大于等于200、小于300          对应           Average 2 
大于等于300                          对应           Poor 3~

*/
QualityLevel GetCo2Level(void)
{
	volatile int32_t cRaw = GetRawData();
	volatile int32_t cLevel = cRaw / 100;
	return (QualityLevel)cLevel;
}

void DisplayCo2Level(QualityLevel lv)
{
	switch (lv)
	{
		case Excellent:
			printf("The air quality of co2 is excellent.\n");
			break;
		case Good:
			printf("The air quality of co2 is good.\n");
			break;
		case Average:
			printf("The air quality of co2 is average.\n");
			break;
		default:
			printf("The air quality of co2 is poor.\n");
			break;
	}
}	
