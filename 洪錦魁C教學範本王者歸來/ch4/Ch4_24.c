/*   程式名稱 : ch4_24.c                  */
/*   巢狀迴路應用                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int year;

    printf("你是否要駕照 ?(y/n) ");
    ch = getche();
    printf("\n");
    if ( ch == 'y' )
    {
       printf("你幾歲 ? ");
       scanf("%d",&year);
       if ( year < 18 )
	      printf("對不起你年齡太小 \n");
       else
	      printf("你需要考駕照 \n");
    }
    system("pause");
    return 0;
}
