/*   程式名稱 : ch11_2.c                  */
/*   &  ( AND )位元運算                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned int  a, b;

    a = 077;     /* 0 開始所以是 8 進位數字 */
    b = 0150;    /* 0 開始所以是 8 進位數字 */
    printf("a & b (10 進位) = %d \n",a&b);
    printf("a & b (8 進位 ) = %o \n",a&b);
    system("pause");
    return 0;
}
