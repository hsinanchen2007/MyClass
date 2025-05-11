#include "tem.h"

static float GetRawData(void)
{
	return 60.0f;
}

float GetCelTem(void)
{
	float cel = GetRawData();
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
