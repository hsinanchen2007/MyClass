/*   程式名稱 : ch3_25.c                  */
/*   輸入華氏溫度將轉成攝氏溫度           */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float f,c;

    printf("請輸入華氏溫度 \n==>");
    scanf("%f",&f);
    c = ( 5.0 / 9.0 ) * ( f - 32.0 );
    printf("攝氏溫度是 %6.2f \n",c);
    system("pause");
    return 0;
}
