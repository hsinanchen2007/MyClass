/*   程式名稱 : ch6_14.c                  */
/*   本程式會列出輸入數字的字串長度 a     */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    void draw();
    int j;

    printf("請輸入字串長度 ==> ");
    scanf("%d",&j);
    draw(j);
    system("pause");
    return 0;
}
void draw(int n)
{
    int i;
/* 下列迴路可列出輸入長度的字元 */ 
    for ( i = 1; i <= n; i++ ) 
       printf("a");
    printf("\n");
}
