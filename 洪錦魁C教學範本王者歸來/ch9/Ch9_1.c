/*   程式名稱 : ch9_1.c                   */
/*   輸入華氏溫度本程式將輸出攝氏溫度     */
#include <stdio.h>
#include <stdlib.h>
typedef   float   tmp;
int main()
{
    tmp  f,c;

    printf("輸入華氏溫度 \n==> ");
    scanf("%f",&f);
    c = ( 5.0 / 9.0 ) * ( f - 32.0 );
    printf("輸出攝氏溫度 %6.2f \n",c);
    system("pause");
    return 0;
}
