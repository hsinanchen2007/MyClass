/*   程式名稱 : ch4_4.c                   */
/*   從 1 加到 9 並列出每ㄧ加後的值       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i = 1;

    printf(" i       總和   \n");
    printf("----------------\n"); 
    for ( i ; i <= 9; i++ )
    {
       sum += i;
       printf(" %d        %d\n",i,sum);
    }   
    system("pause");
    return 0;
}
