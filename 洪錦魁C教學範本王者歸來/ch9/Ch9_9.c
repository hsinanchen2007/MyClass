/*   程式名稱 : ch9_9.c                   */
/*   以函數方式計算平均成績               */
#include <stdio.h>
#include <stdlib.h>
void sum(int i, int j, int k, int index)
{
    static int sum1 = 0;
    static int sum2 = 0;
    static int sum3 = 0;
    sum1 += i;
    sum2 += j;
    sum3 += k;
    if ( index == 4 ) /* 計算完最後ㄧ個元素求平均 */ 
    {
       printf("數學平均 ==> %5.2f\n",sum1/5.0);
       printf("英文平均 ==> %5.2f\n",sum2/5.0);
       printf("電算平均 ==> %5.2f\n",sum3/5.0);
    }
}
int main()
{
    struct score        /* 定義結構資料名稱 */
    {
       int   math;      /* 數學 */
       int   engl;      /* 英文 */
       int   comp;      /* 電腦 */
    } ;
    struct score test[5] = {  /* 直接設定結構陣列內容 */
           { 74, 80, 66 },
           { 72, 90, 77 },
           { 77, 65, 60 },
           { 65, 58, 74 },
           { 81, 79, 68 } };
    int i;

    for ( i = 0; i < 5; i++ )
       sum(test[i].math,test[i].engl,test[i].comp,i);
    system("pause");
    return 0;
}
