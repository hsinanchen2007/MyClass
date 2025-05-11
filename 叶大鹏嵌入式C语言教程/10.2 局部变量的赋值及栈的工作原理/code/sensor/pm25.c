#include <stdint.h>
#include <stdio.h>
#include "pm25.h"

static int32_t GetRawData(void)
{
	return 50;
}

/*
小于10                                  对应           Excellent
大于等于10、小于35             对应           Good
大于等于35、小于75             对应           Average 
大于等于75                           对应           Poor

*/
QualityLevel GetPm25Level(void)
{
	volatile int32_t pRaw = GetRawData();
	volatile QualityLevel pLevel;
	
	if (pRaw < 10)
	{
		pLevel = Excellent;
	}
	else if (pRaw >= 10 && pRaw < 35)
	{
		pLevel = Good;
	}
	else if (pRaw >= 35 && pRaw < 75)
	{
		pLevel = Average;
	}
	else
	{
		pLevel = Poor;
	}
	return pLevel;
}

void DisplayPm25Level(QualityLevel lv)
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
