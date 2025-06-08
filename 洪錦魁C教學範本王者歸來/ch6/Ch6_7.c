/*   祘Α嘿 : ch6_7.c                   */
/*   ―程, 程, ㎝―羆㎝           */
#include <stdio.h>
#include <stdlib.h>
int min(x,y)
int x,y;
{
    if ( x <= y )
       return x;    /* 肚程琌 x */ 
    else
       return y;    /* 肚程琌 y */ 
}
int max(x,y)
int x,y;
{
    if ( x <= y )
       return y;    /* 肚程琌 y */ 
    else
       return x;    /* 肚程琌 x */ 
}
int main()
{
    int num,value,i;
    int tmpmax = -1000;     /* 既﹚程 */ 
    int tmpmin = 1000;      /* 既﹚程 */ 
    int sum = 0;

    printf("叫块戈计ヘ ==> ");
    scanf("%d",&num);
    for ( i = 1; i <= num; i++ )
    {
       printf("叫块计 %d ==> ",i);
       scanf("%d",&value);
       tmpmin = min(value,tmpmin); /* т程 */ 
       tmpmax = max(value,tmpmax); /* т程 */ 
       sum += value;               /* ―羆㎝   */ 
    }
    printf("程 %d \n",tmpmax);
    printf("程 %d \n",tmpmin);
    printf("羆㎝ %d \n",sum);
    system("pause");
    return 0;
}
