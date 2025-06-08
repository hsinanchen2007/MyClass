/*   程式名稱 : ch4_12.c                  */
/*   將輸入數字相反輸出                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int digit,num;

    printf("請輸入任意整數 \n==> ");
    scanf("%d",&num);
    printf("整數的相反輸出 \n==> ");
    while ( num != 0 )
    {
       digit = num % 10;
       num = num / 10;
       printf("%d",digit);
    }
    printf("\n");
    system("pause");
    return 0;
}
