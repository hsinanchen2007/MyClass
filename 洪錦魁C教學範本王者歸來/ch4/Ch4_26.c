/*   程式名稱 : ch4_26.c                  */
/*   列出成績分佈及求平均                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int co90,co80,co70,co60,co_below60;
    int number,sum,score;
    int i;
    float ave;

    co90 = co80 = co70 = co60 = co_below60 = sum = 0;
    printf("請輸入學生人數 ==> ");
    scanf("%d",&number);

    for ( i = 1; i <= number; i++ )
    {
       printf("請輸入學生成績 %d ==> ",i);
       scanf("%d",&score);
       sum += score;
       if ( score >= 90 )
	      co90++;
       else if ( score >= 80 )
	      co80++;
       else if ( score >= 70 )
	      co70++;
       else if ( score >= 60 )
	      co60++;
       else
	      co_below60++;
    }
    ave = (float) sum / ( float ) number;
    printf("%d 個學生成績大於 90 \n",co90);
    printf("%d 個學生成績介於 80 - 90\n",co80);
    printf("%d 個學生成績介於 70 - 80\n",co70);
    printf("%d 個學生成績介於 60 - 70\n",co60);
    printf("%d 個學生成績小於 60   \n",co_below60);
    printf("平均是 %6.2f\n",ave);
    system("pause");
    return 0;
}
