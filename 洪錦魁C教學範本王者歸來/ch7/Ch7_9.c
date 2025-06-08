/*   程式名稱 : ch7_9.c                   */
/*   使用 extern 定義外在變數             */
#include <stdio.h>
#include <stdlib.h>
int f(int i);
int v;
int main()
{
    int  i = 2;

    v = 3;
    printf("i = %d   v = %d    f() = %d \n",i,v,f(i));
    system("pause");
    return 0;
}
