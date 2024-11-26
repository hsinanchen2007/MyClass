#include <stdio.h>

//int say(){
//    printf("hello world\n");
//}
// 1.1函数的形参个数不同, 不能出现同名的函数
//int say(int age){
//    printf("age = %i\n", age);
//}
// 1.2函数的形参类型不同, 不能出现同名的函数
//int say(double height){
//    printf("height = %lf\n", height);
//}
// 1.3函数的返回值类型不同, 不能出现同名的函数
//char say(double height){
//    printf("height = %lf\n", height);
//}

// 3.在函数中不能定义和形参同名的变量
//void test(int num){ // 这里的num就是形参
//    int num;
//}

// 4.如果函数return后面返回的数据类型和函数的返回值类型不同
//   会自动将return后面的数据类型转换为函数的返回值类型
int demo(){
    return 3.14; // 3.14 --> 3
}
int main()
{
    // 1.无论什么情况都不能出现同名的函数
    // 1.1函数的形参个数不同, 不能出现同名的函数
    // 1.2函数的形参类型不同, 不能出现同名的函数
    // 1.3函数的返回值类型不同, 不能出现同名的函数

    // 2.在C语言中, 函数不能嵌套定义(也就是函数中不能定义函数)
    // 注意点: 不同编译器有不同的反馈

    // 3.在函数中不能定义和形参同名的变量
    // 什么是形参? 在函数()中定义的变量就是形参

    // 4.如果函数return后面返回的数据类型和函数的返回值类型不同
    //   会自动将return后面的数据类型转换为函数的返回值类型

    int res = demo();
    printf("res = %i\n", res);

    double res2 = demo();
    printf("res2 = %lf\n", res2);
    return 0;
}
