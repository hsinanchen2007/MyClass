#include "wifi.h"
#include <stdlib.h>

static CbFunc g_cb;

static int32_t ReceiveWifiData(CfgParam *cfgParam)
{
	cfgParam->paramType = 1;//温度传感器校准系数
	cfgParam->size = 4;
	cfgParam->value = (uint8_t *)malloc(cfgParam->size);
	if (cfgParam->value == NULL)
	{
		return -1;
	}
	cfgParam->value[0] = 0x9A;
	cfgParam->value[1] = 0x99;
	cfgParam->value[2] = 0x99;
	cfgParam->value[3] = 0x3F;
	
	return 0;
}

void CreateWifiCb(CbFunc cbFunc)
{
	g_cb = cbFunc;
}

void WifiHandler(void)
{
	CfgParam *cfgParam;
	cfgParam = (CfgParam *)malloc(sizeof(CfgParam));
	if (cfgParam == NULL)
	{
		return;
	}
	if (ReceiveWifiData(cfgParam) != 0)
	{
		free(cfgParam);
		cfgParam = NULL;
		return;
	}
	(*g_cb)(cfgParam);
	
	free(cfgParam->value);
	cfgParam->value = NULL;
	
	free(cfgParam);
	cfgParam = NULL;	
}
