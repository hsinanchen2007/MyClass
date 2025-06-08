/*   程式名稱 : ch9_7.c                   */
/*   結構陣列的應用                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score        /* 定義結構資料名稱 */
    {
       int   math;      /* 數學 */
       int   english;   /* 英文 */
       int   computer;  /* 電腦 */
    } ;
    struct score test[5] = { /* 直接設定結構陣列內容 */ 
           { 74, 80, 66 },
           { 72, 90, 77 },
           { 77, 65, 60 },
           { 65, 58, 74 },
           { 81, 79, 68 } };
    int i,sum1,sum2,sum3;
    float ave1, ave2, ave3;

    sum1 = sum2 = sum3 = 0;
    for ( i = 0; i < 5; i++ )    /* 計算各科成績總和 */ 
    {
       sum1 += test[i].math;
       sum2 += test[i].english;
       sum3 += test[i].computer;
    }
    ave1 = (float) sum1 / 5.0;   /* 求數學平均 */ 
    ave2 = (float) sum2 / 5.0;   /* 求英文平均 */ 
    ave3 = (float) sum3 / 5.0;   /* 求電腦平均 */ 
    printf("數學平均 ==> %8.3f\n",ave1);
    printf("英文平均 ==> %8.3f\n",ave2);
    printf("電腦平均 ==> %8.3f\n",ave3);
    system("pause");
    return 0;
}
