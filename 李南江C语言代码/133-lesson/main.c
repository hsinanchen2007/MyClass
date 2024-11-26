#include <stdio.h>
void change(int *value);
int main()
{
    // 需求: 要求定义一个函数, 在函数中修改传入的基本数据类型变量的值
    int num = 123;
    printf("num = %i\n", num);
    change(&num);
    printf("num = %i\n", num);
    return 0;
}
void change(int *value){
    *value = 666;
}
