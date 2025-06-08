/*   程式名稱 : ch4_27.c                  */
/*   判斷字元型態                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    printf("請輸入字元 ==> ");
    while ( ( ch = getche() ) != '\r' )
    {
       printf("\n");
       if (( ch >= 'A' ) && ( ch <= 'Z' ))
	      printf("這是大寫字元 \n");
       else if (( ch >= 'a' ) && ( ch <= 'z' ))
	      printf("這是小寫字元 \n");
       else if (( ch >= '0' ) && ( ch <= '9' ))
	      printf("這是數字 \n");
       else
	      printf("這是特殊字元 \n");
       printf("請輸入字元 ==> ");
    }
    system("pause");
    return 0;
}
