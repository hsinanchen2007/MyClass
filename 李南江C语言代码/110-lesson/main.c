#include <stdio.h>
int getMax(int values[5], int len);
int main()
{
    // ����: ����һ������, ��ȡ�����е����ֵ
    int nums[5] = {3, 2, 1, 5, 4};
    // 1.��������������ֵ
//    int max = nums[0]; // �����0��Ԫ�ؾ������ֵ
    // 2.��������, ȡ������Ԫ��
    int len = sizeof(nums) / sizeof(nums[0]);
//    for(int i = 1; i < len ; i++){
//        // 3.���õ�ǰ��������Ԫ�غ����ֵ���бȽ�
//        if(nums[i] > max){
//            // 4.�����ֵ�޸�Ϊ��ǰ��Ԫ��
//            max = nums[i];
//        }
//    }
    int max = getMax(nums, len);
    // 5.������
    printf("max = %i\n", max);
    return 0;
}

int getMax(int values[5], int len){
    // 1.��������������ֵ
    int max = values[0]; // �����0��Ԫ�ؾ������ֵ
    // 2.��������, ȡ������Ԫ��
    for(int i = 1; i < len ; i++){
        // 3.���õ�ǰ��������Ԫ�غ����ֵ���бȽ�
        if(values[i] > max){
            // 4.�����ֵ�޸�Ϊ��ǰ��Ԫ��
            max = values[i];
        }
    }
    // 5.�������ֵ
    return max;

}
