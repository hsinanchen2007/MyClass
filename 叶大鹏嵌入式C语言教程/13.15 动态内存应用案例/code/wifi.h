#ifndef _WIFI_H_
#define _WIFI_H_

#include <stdint.h>

typedef struct
{
	uint8_t paramType;
	uint8_t *value;
	uint32_t size;
} CfgParam;

typedef void (*CbFunc)(CfgParam *cfgParam);

void CreateWifiCb(CbFunc cbFunc);

void WifiHandler(void);
#endif
