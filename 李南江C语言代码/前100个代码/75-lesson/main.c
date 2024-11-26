#include <stdio.h>

int getSum(int a, int b){
    int res = a + b;
    return res;
}

int main()
{
    /*
     * 1.定义函数的格式
       返回值类型 函数名称(形参列表){
           被函数封装的内容
       }
       2.定义函数的步骤:
       2.1给函数起一个有意义的名称
          函数名称也是标识符的一种, 所以也需要遵守标识符的规则和规范
       2.2确定函数的形参列表
          确定别人在使用函数的时候, 是否需要传入一些辅助数据
          (数据类型 变量名称, 数据类型 变量名称, ....)
          形参列表可以有0个或多个
       2.3在{}中编写函数的业务逻辑
       2.4确定函数的返回值和返回值类型
          返回值类型必须和return后面数据的类型一致
     */
    // 需求: 要求求两个变量的和
    int num1 = 10;
    int num2 = 20;
//    int res = num1 + num2;
    int res = getSum(num1, num2);
    printf("res = %i\n", res);

//    int value1 = 30;
//    int value2 = 50;
//    int res2 = value1 + value2;
//    printf("res = %i\n", res2);
    return 0;
}
