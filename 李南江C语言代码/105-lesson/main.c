#include <stdio.h>

int main()
{
    /*
     * 1.ʲô������ı���?
     * ����ı�������ȡ�����������е�Ԫ��
     */
    int ages[5] = {1, 3, 5, 7, 9};
//    printf("ages[0] = %i\n", ages[0]);
//    printf("ages[1] = %i\n", ages[1]);
//    printf("ages[2] = %i\n", ages[2]);
//    printf("ages[3] = %i\n", ages[3]);
//    printf("ages[4] = %i\n", ages[4]);

//    for(int i = 0; i < 10; i++){
////        printf("i = %i\n", i);
//        printf("ages[%i] = %i\n", i, ages[i]);
//    }

    // 1.sizeof(��������)�õ���������ռ�õ��ܴ�С
//    int size = sizeof(ages);
//    printf("size = %i\n", size);

    // 2.sizeof(��������[����])�õ�����������ÿһ��Ԫ�صĴ�С
//    int size = sizeof(ages[2]);
//    printf("size = %i\n", size);

    int len = sizeof(ages) / sizeof(ages[1]);
    printf("len = %i\n", len);

    for(int i = 0; i < len; i++){
//        printf("i = %i\n", i);
        printf("ages[%i] = %i\n", i, ages[i]);
    }
    return 0;
}
