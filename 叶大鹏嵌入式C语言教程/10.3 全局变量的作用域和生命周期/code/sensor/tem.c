#include "tem.h"

extern float g_temCof;

static float GetRawData(void)
{
	return 20.0f;
}

float GetCelTem(void)
{
	float cel = GetRawData();
	
	cel *= g_temCof;
	if (cel < CEL_MIN_VALUE)
	{
		cel = CEL_MIN_VALUE;
	}
	if (cel > CEL_MAX_VALUE)
	{
		cel = CEL_MAX_VALUE;
	}
	return cel;
}

float GetFahTem(void)
{
	float raw = GetRawData();
	float fah = CEL_TO_FAH(raw) * 1.2f;

	return fah;
}
