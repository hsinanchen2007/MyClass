/*   程式名稱 : ch16_2.c                  */
/*   基本 malloc 應用                     */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    char  *str;

    if (( str = (char *) malloc(80*sizeof(char))) == NULL)
    {
       printf("無法取得記憶體空間 \n");
       exit(1);
    }
    printf("取輸入句子 \n");
    gets(str);
    printf("你輸入的句子是 \n");
    puts(str);
    system("pause");
    return 0;
}
