/*   程式名稱 : ch8_1.c                   */
/*   簡易 #define 的應用                  */
#include <stdio.h>
#include <stdlib.h>
#define   a    10
#define   b    20

int main()
{
    int  sum;

    sum = a + b;
    printf("總和 = %d\n",sum);
    system("pause");
    return 0;
}
