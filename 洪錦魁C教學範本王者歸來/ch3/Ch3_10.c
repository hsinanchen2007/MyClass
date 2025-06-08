/*   程式名稱 : ch3_10.c                  */
/* 數字字元輸出與碼值的應用               */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch1, ch2;    

    ch1 = '2';            /*    字元變數值設為 2 */ 
    ch2 = 2;              /*  字元變數碼值設為 2 */ 
    printf("ch = %c\n",ch1);           /* 印變數 */ 
    printf("ASCII of ch1 = %d\n",ch1); /* 印碼值 */ 
    printf("ch = %c\n",ch2);           /* 印變數 */
    printf("ASCII of ch2 = %d\n",ch2); /* 印碼值 */
    system("pause");
    return 0;
}
