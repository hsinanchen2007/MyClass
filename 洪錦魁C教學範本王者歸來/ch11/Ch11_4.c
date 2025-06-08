/*   程式名稱 : ch11_4.c                  */
/*    | ( or ) 位元運算                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 077;
    b = a | 3;
    printf("a | b (10 進位) = %d \n",b);
    b |= 7;
    printf("a | b (10 進位) = %d \n",b);
    system("pause");
    return 0;
}
