/*   程式名稱 : ch11_1.c                  */
/*   &  ( AND )位元運算                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 25;
    b = 77;
    printf("a & b = %d \n",a&b);
    a &= b;
    printf("a     = %d \n",a);
    system("pause");
    return 0;
}
