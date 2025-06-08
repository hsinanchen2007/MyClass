/*   祘Α嘿 : ch4_21.c                  */
/*   计案计耞                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number, rem;

    printf("叫块ヴ種 ==> ");
    scanf("%d",&number);
    rem = number % 2;
    if ( rem == 1 )
       printf("%d 琌计 \n",number);
    else
       printf("%d 琌案计 \n",number);
    system("pause");
    return 0;   
}
