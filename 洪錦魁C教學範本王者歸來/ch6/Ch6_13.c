/*   程式名稱 : ch6_13.c                  */
/*   列印相反字元的遞迴函數應用           */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 5;     /* 設定輸入 5 個字元 */ 
    void palindrom(int n);

    palindrom(i);
    printf("\n");
    system("pause");
    return 0;
}
void palindrom(n)
int n;
{
    char next;

    if ( n <= 1 ) /* 讀到最後ㄧ個字元此條件會成立  */ 
    {
       next = getche();
       printf("\n");
       putchar(next);
    }
    else
    {
       next = getche();   /* 讀字元   */ 
       palindrom(n-1);    /* 呼叫自己 */ 
       putchar(next);
    }
}
