#ifndef _CO2_H_
#define _CO2_H_

#include "sensor_common.h"

enum QualityLevel GetCo2Level(void);
void DisplayCo2Level(enum QualityLevel lv);
#endif
