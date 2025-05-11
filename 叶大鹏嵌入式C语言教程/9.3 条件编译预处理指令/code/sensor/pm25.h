#ifndef _PM25_H_
#define _PM25_H_
#include "sensor_common.h"

enum QualityLevel GetPm25Level(void);
void DisplayPm25Level(enum QualityLevel lv);
#endif
