/**
 ******************************************************************************
 * @file      tem.c
 * @author    YeDapeng
 * @version   V1.0.0
 * @date      20220209
 * @brief     �����¶���ص����� 
 ******************************************************************************
 */

#include "tem.h"
#include <stdint.h>
#include <stdio.h>

static float g_temCof;

static float GetRawData(void)
{
	static uint8_t s_chgVal; //��̬�ֲ�����ֻ�����һ�γ�ʼ��
	s_chgVal++;
	s_chgVal %= 5;
	return 20.0f + s_chgVal;
}

/**
 ******************************************************************************
 * @brief �����¶�У׼ϵ��
 * @param temCof: ����������¶Ƚ�׼ϵ��
 * @return 
 ******************************************************************************
 */
void SetTemCof(float temCof)
{
	g_temCof = temCof;
}

static float CalRawAvg(float *data, uint32_t len)
{
	float res = 0;
	for (uint32_t i = 0; i < len; i++)
	{
		res += data[i];
	}
	return res /= 5;
}

/**
 ******************************************************************************
 * @brief �ṩ�����¶�����
 * @param 
 * @return �����¶���ֵ
 ******************************************************************************
 */
float GetCelTem(void)
{
//	float cel1 = GetRawData();
//	printf("cel1 = %.1f.\n", cel1);
//	float cel2 = GetRawData();
//	printf("cel2 = %.1f.\n", cel2);
//	float cel3 = GetRawData();
//	printf("cel3 = %.1f.\n", cel3);
//	float cel4 = GetRawData();
//	printf("cel4 = %.1f.\n", cel4);
//	float cel5 = GetRawData();
//	printf("cel5 = %.1f.\n", cel5);

//	float cel = (cel1 + cel2 + cel3 + cel4 + cel5) / 5;
	float raw[5];
	for (uint32_t i = 0; i < 5; i++)
	{
		raw[i] = GetRawData();
	}
	
	float cel = 0;
	cel = CalRawAvg(raw, 5);
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

/**
 ******************************************************************************
 * @brief �ṩ�����¶�����
 * @param 
 * @return �����¶���ֵ
 ******************************************************************************
 */
float GetFahTem(void)
{
	float raw = GetRawData();
	float fah = CEL_TO_FAH(raw) * 1.2f;

	return fah;
}
