/*   程式名稱 : ch3_16.c                  */
/*   scanf 和 printf 應用                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,k,sum;
    char ch1,ch2;
    float x1,x2,ave;

    printf("請輸入 2 個字元 \n==>");
    scanf("%c%c",&ch1,&ch2);
    printf("2 個字元的相反輸出是 \n==>");
    printf("%c%c\n",ch2,ch1);
    printf("請輸入 3 個整數 \n==>");
    scanf("%d %d %d",&i,&j,&k);
    sum = i + j + k;
    printf("總和是 ==> %d\n",sum);
    printf("請輸入 2 個浮點數 \n==>");
    scanf("%f %f",&x1,&x2);
    ave = ( x1 + x2 ) / 2.0;
    printf("平均是 ==> %6.2f\n",ave);
    system("pause");
    return 0; 
}
