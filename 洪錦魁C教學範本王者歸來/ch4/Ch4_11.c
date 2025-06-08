/*   祘Α嘿 : ch4_11.c                  */
/*   ―程そ计                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,tmp;

    printf("叫块 2 タ俱计 \n==> ");
    scanf("%d %d",&i,&j);
    while ( j != 0 )
    {
       tmp = i % j;
       i = j;
       j = tmp;
    }
    printf("程そ计琌 %d \n",i);
    system("pause");
    return 0;
}
