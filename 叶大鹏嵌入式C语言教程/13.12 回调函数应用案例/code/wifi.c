#include "wifi.h"

static CfgParam g_cfgParam;
static CbFunc g_cb;

static int32_t ReceiveWifiData(void)
{
	g_cfgParam.paramType = 1;//温度传感器校准系数
	g_cfgParam.value[0] = 0x9A;
	g_cfgParam.value[1] = 0x99;
	g_cfgParam.value[2] = 0x99;
	g_cfgParam.value[3] = 0x3F;
	g_cfgParam.size = 4;
	return 0;
}

void CreateWifiCb(CbFunc cbFunc)
{
	g_cb = cbFunc;
}

void WifiHandler(void)
{
	if (ReceiveWifiData() != 0)
	{
		return;
	}
	(*g_cb)(&g_cfgParam);
}