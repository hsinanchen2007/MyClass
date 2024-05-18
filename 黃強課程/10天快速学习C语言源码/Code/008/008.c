#include <stdio.h>

int main()
{
    int a = 5 + 10;//用变量a存放 加法的结果
    int b = 5 - 10;//同理，用变量b存放结果
    int c = 5 * 10;//相乘 *，不是X
    int d = 5 / 10;//相除 /，也不是数学中的除号 
    int  e = 5 % 10;//取余数 %

    printf("5+10 = %d\n", a);
    printf("5-10 = %d\n", b);
    printf("5*10 = %d\n", c);
    printf("5/10 = %d\n", d);
    printf("5 %%10 = %d\n", e); //如果想输出%，需要两个%
}
 