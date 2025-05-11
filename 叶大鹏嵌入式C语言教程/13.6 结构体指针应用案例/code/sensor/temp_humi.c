/**
 ******************************************************************************
 * @file      tem.c
 * @author    YeDapeng
 * @version   V1.0.0
 * @date      20220209
 * @brief     �����¶���ص����� 
 ******************************************************************************
 */

#include "temp_humi.h"
#include <stdint.h>
#include <stdio.h>

static float g_temCof;

static float GetRawData(uint32_t sensorId)
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
float GetCelTem(uint32_t sensorId)
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
float GetFahTem(uint32_t sensorId)
{
	float raw = GetRawData(sensorId);
	float fah = CEL_TO_FAH(raw) * 1.2f;

	return fah;
}

/**
 ******************************************************************************
 * @brief �ṩʪ������
 * @param  ������ID
 * @return ʪ����ֵ
 ******************************************************************************
 */
uint8_t GetHumiData(uint32_t sensorId)
{
	return 40;
}

/**
 ******************************************************************************
 * @brief  ��ȡ�¶�ʪ������
 * @param  sensorId��������ID
 * @param  temp�������¶�����
 * @param  humi������ʪ������
 * @return 0���ɹ� -1��ʧ��
 ******************************************************************************
 */
//int8_t GetTempHumi(uint32_t sensorId, float *temp, uint8_t *humi)
//{
//	*temp = GetCelTem(sensorId);
//	*humi = GetHumiData(sensorId);
//	return 0;
//}

int8_t GetTempHumi(TempHumiSensor *tempHumiPtr)
{
	tempHumiPtr->temp = GetCelTem(tempHumiPtr->id);
	tempHumiPtr->humi = GetHumiData(tempHumiPtr->id);
	return 0;
}
