/*   程式名稱 : ch9_10.c                  */
/*   宣告外在結構傳遞結構至函數           */
#include <stdio.h>
#include <stdlib.h>
struct score     /* 定義結構資料名稱 */
{
    int  math;   /* 數學 */
    int  engl;   /* 英文 */
    int  comp;   /* 電腦 */
};
void sum(struct score sc, int index)
{
    static int sum1 = 0;
    static int sum2 = 0;
    static int sum3 = 0;
    sum1 += sc.math;
    sum2 += sc.engl;
    sum3 += sc.comp;
    if ( index == 4 )   /* 讀完最後ㄧ筆資料則求平均 */
    {
       printf("數學平均 ==> %5.2f\n",sum1/5.0);
       printf("英文平均 ==> %5.2f\n",sum2/5.0);
       printf("電算平均 ==> %5.2f\n",sum3/5.0);
    }
}
int main()
{
    struct score test[5];
    int i;

    printf("請輸入下列分數 \n");
    printf("數學 英文 電算\n");
    for ( i = 0; i < 5; i++ )
    {
       scanf("%d%d%d",&test[i].math,&test[i].engl,&test[i].comp);
       sum(test[i],i);
    }
    system("pause");
    return 0;
}
