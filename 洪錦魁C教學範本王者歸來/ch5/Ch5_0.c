/*   程式名稱 : ch5_1.c                   */
/*   輸入學生人數及成績可求出平均成績     */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int score[10],i,sum,num;
    float ave;

    sum = 0;
    printf("請輸入學生人數 ==> ");
    scanf("%d",&num);
    for ( i = 0; i < num; i++ )
    {
       printf("請輸入分數 ==> ");
       scanf("%d",&score[i]);
       sum += score[i];
    }
    ave = (float) sum / (float) num;
    printf("平均分數是 %6.2f \n",ave);
    system("pause");
    return 0; 
}
