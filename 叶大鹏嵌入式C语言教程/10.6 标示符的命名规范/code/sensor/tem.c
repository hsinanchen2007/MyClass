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
static float g_temCof;

static float GetRawData(void)
{
	static uint8_t s_chgVal; //��̬�ֲ�����ֻ�����һ�γ�ʼ��
	s_chgVal = 0;
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
 * @param 
 * @return �����¶���ֵ
 ******************************************************************************
 */
float GetCelTem(void)
{
	float cel1 = GetRawData();
	printf("cel1 = %.1f.\n", cel1);
	float cel2 = GetRawData();
	printf("cel2 = %.1f.\n", cel2);
	float cel3 = GetRawData();
	printf("cel3 = %.1f.\n", cel3);
	float cel4 = GetRawData();
	printf("cel4 = %.1f.\n", cel4);
	float cel5 = GetRawData();
	printf("cel5 = %.1f.\n", cel5);

	float cel = (cel1 + cel2 + cel3 + cel4 + cel5) / 5;
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
