#include <stdio.h>
void printArray(int values[5], int len);
int main()
{
    /*
     * ����: Ҫ����һ������, ���ڱ������������
     */
    int ages[5] = {1, 3, 5, 7, 9};
    int len = sizeof(ages) / sizeof(ages[1]);
//    for(int i = 0; i < len; i++){
//        printf("ages[%i] = %i\n", i, ages[i]);
//    }
    /*
     * �������������б����������ĵ�ַ, ���Դ��ݸ������ľ�������ĵ�ַ
     * ������C�����е�ַҲ��һ����������, ����������ǳ�֮Ϊָ������
     * ָ��������32λ��������ռ��4���ֽ�, ��64λ��������ռ8���ֽ�
     * �����ں�����ͨ��sizeof�����������ָ�����͵Ĵ�С, ����������Ĵ�С
     */
    // ����: �����ں����м��㴫������ĳ���
    printArray(ages, len);
//    printf("ages size = %i\n", sizeof(ages));
    return 0;
}
void printArray(int values[5], int len){
//    printf("values size = %i\n", sizeof(values));
//    int len = sizeof(values) / sizeof(values[1]);
    for(int i = 0; i < len; i++){
        printf("values[%i] = %i\n", i, values[i]);
    }
}
