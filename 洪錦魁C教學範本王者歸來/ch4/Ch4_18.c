/*   程式名稱 : ch4_18.c                  */
/*   使用 do .. while 繪製樓梯            */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;

    i = 1;
    do
    {
       j = i;
       do {
	      printf("  ");
       }  while ( j++ <= 9 );
       j = 1;
       do {
	      printf("%c%c",97,97);
       }  while ( j++ < i );
       printf("\n");
    } while ( i++ <= 9 );
    system("pause");
    return 0;
}
