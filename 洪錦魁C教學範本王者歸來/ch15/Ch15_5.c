/*   程式名稱 : ch15_5.c                  */
/*   將整數轉成字串                       */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int radix1 = 10;
    int radix2 = 16;
    int value1 = 1567;
    int value2 = 3445;
    char str1[80];
    char str2[80];

    itoa(value1,str1,radix1);
    itoa(value2,str2,radix2);
    printf("%s \n",str1);
    printf("%s \n",str2);
    system("pause");
    return 0;
}
