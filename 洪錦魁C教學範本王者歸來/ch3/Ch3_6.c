/*   程式名稱 : ch3_6.c                   */
/*   格式化浮點數輸出                     */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float i;

    i = 123.56;
    printf("/%f/\n",i);
    printf("/%3.2f/\n",i);
    printf("/%8.2f/\n",i);
    printf("/%-8.2f/\n",i);
    printf("/%+8.2f/\n",i);
    printf("/%08.2f/\n",i);
    system("pause");
    return 0;
}
