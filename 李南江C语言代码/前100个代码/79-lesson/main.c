#include <stdio.h>

void change(int value){ // 这里的value就是形参
    value = 666;
}
int main()
{
    /*
     * 在函数中修改形参, 不会影响到外界的实参?
     * 形参: 就是在函数()中定义的变量
     * 实参: 就是调用函数的时候传递的参数
     *
     * 注意点:
     * 这种特性只有函数的形参是基本数据类型的时候才会出现
     * int char float double
     */
    int num = 123;
    printf("num = %i\n", num); // 123
    change(num); // 这里的num就是实参
    printf("num = %i\n", num); // 666? 123?
    return 0;
}
