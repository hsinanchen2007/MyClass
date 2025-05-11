#ifndef _SENSOR_COMMON_H_
#define _SENSOR_COMMON_H_

#include "temp_humi.h"

typedef enum
{
	Excellent,
	Good,
	Average,
	Poor
}QualityLevel;

typedef struct
{
	TempHumiSensor tempHumiData[TEMP_SENSOR_NUM];
	QualityLevel co2Level;
	QualityLevel pm25Level;
} AirQuality;

#endif
