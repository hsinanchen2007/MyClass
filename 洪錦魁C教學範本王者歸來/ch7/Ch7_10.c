/*   �{���W�� : ch7_10.c                  */
/*   register �ŧi����                    */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    register  int  i; /* �ŧi register �ܼ� */ 
    int  tmp = 0;

    for ( i = 1; i <= 100; i++ )
       tmp += i;
    printf("�`�M = %d\n",tmp);
    system("pause");
    return 0;
}
