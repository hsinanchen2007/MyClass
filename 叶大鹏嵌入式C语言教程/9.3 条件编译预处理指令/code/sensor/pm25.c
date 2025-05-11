#include <stdint.h>
#include <stdio.h>
#include "pm25.h"

static int32_t GetRawData(void)
{
	return 50;
}

/*
С��10                                  ��Ӧ           Excellent
���ڵ���10��С��35             ��Ӧ           Good
���ڵ���35��С��75             ��Ӧ           Average 
���ڵ���75                           ��Ӧ           Poor

*/
enum QualityLevel GetPm25Level(void)
{
	int32_t raw = GetRawData();
	enum QualityLevel level;
	
	if (raw < 10)
	{
		level = Excellent;
	}
	else if (raw >= 10 && raw < 35)
	{
		level = Good;
	}
	else if (raw >= 35 && raw < 75)
	{
		level = Average;
	}
	else
	{
		level = Poor;
	}
	return level;
}

void DisplayPm25Level(enum QualityLevel lv)
{
	switch (lv)
	{
		case Excellent:
			printf("The air quality of pm2.5 is excellent.\n");
			break;
		case Good:
			printf("The air quality of pm2.5 is good.\n");
			break;
		case Average:
			printf("The air quality of pm2.5 is average.\n");
			break;
		default:
			printf("The air quality of pm2.5 is poor.\n");
			break;
	}
}