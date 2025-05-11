#ifndef _PM25_H_
#define _PM25_H_
#include "sensor_common.h"

QualityLevel GetPm25Level(void);
void DisplayPm25Level(QualityLevel lv);

#endif
