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

static float GetRawData(uint8_t sensorId)
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

/**
 ******************************************************************************
 * @brief �ṩ�����¶�����
 * @param  ������ID
 * @return �����¶���ֵ
 ******************************************************************************
 */
float GetCelTem(uint8_t sensorId)
{
	float cel = GetRawData(sensorId);

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
 * @param  ������ID
 * @return �����¶���ֵ
 ******************************************************************************
 */
float GetFahTem(uint8_t sensorId)
{
	float raw = GetRawData(sensorId);
	float fah = CEL_TO_FAH(raw) * 1.2f;

	return fah;
}
