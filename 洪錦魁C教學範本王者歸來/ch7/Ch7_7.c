/*   程式名稱 : ch7_7.c                   */
/*   所有變數皆宣告為外在變數             */
#include <stdio.h>
#include <stdlib.h>
int a, b, c;       /* 宣告外在變數 */ 

void add()
{
    c = a + b;
}
int main()
{
    a = b = 4;
    add();
    printf("c = %d \n",c);
    system("pause");
    return 0;
}
