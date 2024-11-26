#include <stdio.h>

int main()
{
    /*
     * 1.什么是数组的遍历?
     * 数组的遍历就是取出数组中所有的元素
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

    // 1.sizeof(数组名称)得到的是数组占用的总大小
//    int size = sizeof(ages);
//    printf("size = %i\n", size);

    // 2.sizeof(数组名称[索引])得到的是数组中每一个元素的大小
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
