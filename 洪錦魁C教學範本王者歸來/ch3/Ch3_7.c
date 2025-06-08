/*   程式名稱 : ch3_7.c                   */
/*   格式化字元輸出                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char i;

    i = 'a';
    printf("/%c/\n",i);
    printf("/%3c/\n",i);
    printf("/%-3c/\n",i);
    system("pause");
    return 0;
}
