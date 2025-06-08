/*   程式名稱 : ch12_2.c                  */
/*   計算英文字母個數                     */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    char ch;
    
    printf("請輸入任意英文字母或數字\n");
    while ( ( ch = getche() ) != '\r' )
       isalpha(ch) ? (count++) : ( count=count );
    printf("\n英文字母個數 = %d\n",count);
    system("pause");
    return 0;
}
