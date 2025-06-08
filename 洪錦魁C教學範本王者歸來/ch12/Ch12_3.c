/*   程式名稱 : ch12_3.c                  */
/*   測試 isascii() 函數                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 0; i < 130 ; i++ )
    {
       if ( isascii(i) == 0 )
          printf("i = %d 不是 ascii 碼值\n",i);
    }
    system("pause");
    return 0;
}
