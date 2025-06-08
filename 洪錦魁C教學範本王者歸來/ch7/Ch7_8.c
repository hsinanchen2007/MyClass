/*   程式名稱 : ch7_8.c                       */
/*   某一變數同時被宣告為外在和區域變數的應用 */
#include <stdio.h>
#include <stdlib.h>
int a, b, c;

void add()
{
    int a;             /* 區域變數 */ 
    a = 3;
    c = a + b;         /* a 值是區域變數 3 */ 
}
int main()
{
    a = b = 4;
    add();
    printf("c = %d \n",c);
    system("pause");
    return 0;
}
