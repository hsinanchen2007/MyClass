/*   程式名稱 : ch3_17.c                    */
/*   scanf常發生的錯誤                      */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    char ch;

    printf("請輸入 1 個整數 \n==>");
    scanf("%d",&i);
    printf("請輸入 1 個字元 \n==>");
    scanf("%c",&ch);
    printf("整數是=%d, Ascii碼值是=%d, 字元是=%c \n",i,ch,ch);
    system("pause");
    return 0; 
}
 
