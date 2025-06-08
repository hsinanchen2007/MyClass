/*   程式名稱 : ch11_10.c                 */
/*   >> 位元右移運算                      */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 15;
    b = a >> 1;
    printf("位元右移 1 次 = %d \n",b);
    b = a >> 3;
    printf("位元右移 3 次 = %d \n",b);
    system("pause");
    return 0;
}
