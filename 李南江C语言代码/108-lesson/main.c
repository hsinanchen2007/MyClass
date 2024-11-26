#include <stdio.h>
void change(int value);
void change2(int values[3]);
int main()
{
    /*
     * 1.数组作为函数的参数
     * 数组名作为函数的参数, 在函数内修改形参, 会影响到外界的实参
     *
     * 2.基本数据类型作为函数的参数
     * char int float double
     * 在函数内修改形参, 不会影响到外界的实参
     */
//    int num = 123;
//    printf("num = %i\n", num);
//    change(num);
//    printf("num = %i\n", num);

    int ages[3] = {1, 3, 5};
    printf("ages[1] = %i\n", ages[1]);
    // 由于数组名保存的就是数组的地址
    // 由于数组名 == &数组名 == &数组名[0]
    // 所以这个地方相当于把数组的地址传递给了形参
    change2(ages);
    printf("ages[1] = %i\n", ages[1]);

//    printf("ages = %p\n", ages);
//    printf("&ages = %p\n", &ages);
//    printf("&ages[0] = %p\n", &ages[0]);
    return 0;
}
void change2(int values[3]){
    values[1] = 666;
}
void change(int value){
    value = 666;
}
