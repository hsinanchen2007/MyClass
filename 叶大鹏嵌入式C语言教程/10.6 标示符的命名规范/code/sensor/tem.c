/**
 ******************************************************************************
 * @file      tem.c
 * @author    YeDapeng
 * @version   V1.0.0
 * @date      20220209
 * @brief     处理温度相关的数据 
 ******************************************************************************
 */

#include "tem.h"
#include <stdint.h>
static float g_temCof;

static float GetRawData(void)
{
	static uint8_t s_chgVal; //静态局部变量只会进行一次初始化
	s_chgVal = 0;
	s_chgVal++;
	s_chgVal %= 5;
	return 20.0f + s_chgVal;
}

/**
 ******************************************************************************
 * @brief 设置温度校准系数
 * @param temCof: 输入参数，温度较准系数
 * @return 
 ******************************************************************************
 */
void SetTemCof(float temCof)
{
	g_temCof = temCof;
}
/**
 ******************************************************************************
 * @brief 提供摄氏温度数据
 * @param 
 * @return 摄氏温度数值
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
 * @brief 提供华氏温度数据
 * @param 
 * @return 华氏温度数值
 ******************************************************************************
 */
float GetFahTem(void)
{
	float raw = GetRawData();
	float fah = CEL_TO_FAH(raw) * 1.2f;

	return fah;
}
