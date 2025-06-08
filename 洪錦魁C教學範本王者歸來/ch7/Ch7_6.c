/*   程式名稱 : ch7_6.c                   */
/*   外在 external 變數的應用             */
#include <stdio.h>
#include <stdlib.h>
int val;              /* 宣告外在變數 */ 

void max(int a, int b)
{
    val = ( a > b ) ? a : b;
}
int main()
{
    int c = 5;
    int d = 6;

    max( c, d );
    printf("較大值 = %d \n",val);
    system("pause");
    return 0;
}
