/*   程式名稱 : ch6_8.c                   */
/*   求平均值                             */
#include <stdio.h>
#include <stdlib.h>
float avg(var,num)
int var[];
int num;
{
    float ave = 0.0;
    int i;

    for ( i = 0; i < num; i++ )
       ave += var[i];      /* 求總和   */ 
    ave /= (float) num;    /* 求平均   */ 
    return ave;            /* 傳回平均 */ 
}
int main()
{
    int array[5];
    float average;
    int i;

    for ( i = 0; i < 5; i++ )
    {
       printf("請輸入數值 %d ==> ",i+1);
       scanf("%d",&array[i]);
    }
    average = avg(array,5);
    printf("平均值是 %6.2f \n",average);
    system("pause");
    return 0;
}
