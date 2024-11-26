#include <stdio.h>
void printArray(int values[5], int len);
int main()
{
    /*
     * 需求: 要求定义一个函数, 用于遍历传入的数组
     */
    int ages[5] = {1, 3, 5, 7, 9};
    int len = sizeof(ages) / sizeof(ages[1]);
//    for(int i = 0; i < len; i++){
//        printf("ages[%i] = %i\n", i, ages[i]);
//    }
    /*
     * 由于数组名称中保存的是数组的地址, 所以传递给函数的就是数组的地址
     * 由于在C语言中地址也是一种数据类型, 这个种类我们称之为指针类型
     * 指针类型在32位编译器下占用4个字节, 在64位编译器下占8个字节
     * 所以在函数中通过sizeof计算出来的是指针类型的大小, 而不是数组的大小
     */
    // 结论: 不能在函数中计算传入数组的长度
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
