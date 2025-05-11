#include <stdint.h>
#include <stdio.h>
#include "co2.h"

static int32_t GetRawData(void)
{
	return 200;
}

/*
小于100                                 对应           Excellent 0
大于等于100、小于200          对应           Good 1
大于等于200、小于300          对应           Average 2 
大于等于300                          对应           Poor 3

*/
enum QualityLevel GetCo2Level(void)
{
	int32_t raw = GetRawData();
	int32_t level = raw / 100;
	return (enum QualityLevel)level;
}

void DisplayCo2Level(enum QualityLevel lv)
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