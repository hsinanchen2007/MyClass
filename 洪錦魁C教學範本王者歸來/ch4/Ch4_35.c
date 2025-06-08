/*   程式名稱 : ch4_35.c                  */
/*   goto 指令應用                        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;

start:
    printf("請輸入 2 個數字 \n==> ");
    scanf("%d%d",&i,&j);
    if ( i > j )   /* 如果第 1 數字大於第 2 數字 */ 
       goto stop;  /* 跳至 stop 程式結束 */ 
    goto start;
stop:
    printf("程式結束 \n");
    system("pause");
    return 0;
}
