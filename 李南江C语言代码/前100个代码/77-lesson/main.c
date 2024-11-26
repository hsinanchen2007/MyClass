#include <stdio.h>

int getAge(){
    return 18;
}
int getSum(int a, int b){
    int res = a + b;
    return res;
}
void say(int age){
    printf("age = %i\n", age);
}

int test1(){
    return 666;
}
float test2(){
    return 1.11;
}
double test3(){
    return 3.14;
}
char test4(){
    return 'a';
}
int main()
{
    // 1.函数可以有形参, 也可以没有形参
//    getAge();
//    getSum(10, 20);
    // 2.函数的形参可以有零个或多个
//    say(18);
    // 3.函数可以有返回值, 也可以没有返回值
    // 4.函数如果没有返回值, 那么函数的返回值类型推荐编写void
    // 5.函数的返回值类型, 可以是C语言中的任意类型
    printf("%i\n", test1());
    printf("%f\n", test2());
    printf("%lf\n", test3());
    printf("%c\n", test4());
    return 0;
}
