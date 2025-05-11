#include <stdint.h>
#include <stdio.h>
#include "co2.h"

static int32_t GetRawData(void)
{
	return 200;
}

/*
С��100                                 ��Ӧ           Excellent 0
���ڵ���100��С��200          ��Ӧ           Good 1
���ڵ���200��С��300          ��Ӧ           Average 2 
���ڵ���300                          ��Ӧ           Poor 3

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