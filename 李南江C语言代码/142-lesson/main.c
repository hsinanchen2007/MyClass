#include <stdio.h>
int minus(int a, int b);
int sum(int a, int b);
int calculate(int a, int b, int (*fn)(int a, int b));
int main()
{
    // 需求: 定义一个函数, 想让函数返回和时就返回和, 想让函数返回差时就返回差
    /*
    int (*fn)(int a, int b);
    fn = minus;
    // 当前fn指针指向了minus函数, 所以调用的就是Minus函数
    int res = fn(10, 20);
    printf("res = %i\n", res);

    fn = sum;
    // 当前fn指针指向了sum函数, 所以调用的就是Sum函数
    int res2 = fn(10, 20);
    printf("res2 = %i\n", res2);
    // 结论: 指针变量指向谁, 调用的就是谁
    */
//    int res = calculate(10, 20, minus);
    int res = calculate(10, 20, sum);
    printf("res = %i\n", res);
    return 0;
}

int calculate(int a, int b, int (*fn)(int a, int b)){
    return fn(a, b);
}

int minus(int a, int b){
    return a - b;
}
int sum(int a, int b){
    return a + b;
}
