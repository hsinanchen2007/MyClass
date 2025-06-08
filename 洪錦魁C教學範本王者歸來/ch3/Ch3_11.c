/*   程式名稱 : ch3_11.c                  */
/*   列印特殊笑臉圖形                     */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    char i1 = 1,i2 = 2;

    printf("%c%c%c%c%c\n",i2,i2,i1,i2,i2);
    printf("%c%c%c%c%c\n",i2,i1,i1,i1,i2);
    printf("%c%c%c%c%c\n",i1,i1,i1,i1,i1);
    printf("%c%c%c%c%c\n",i2,i1,i1,i1,i2);
    printf("%c%c%c%c%c\n",i2,i2,i1,i2,i2);
    system("pause");
    return 0;
}
