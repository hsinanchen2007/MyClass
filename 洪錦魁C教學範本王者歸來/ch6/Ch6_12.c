/*   �{���W�� : ch6_12.c                  */
/*   �D���������j��Ƴ]�p                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int factorial();

    for ( i = 0; i < 5; i++ )  /* �D 0 �� 4 ������ */ 
       printf("%d!  =  %d \n",i,factriol(i));
    system("pause");
    return 0;   
}
int factriol(j)
int j;
{
    int sum;                         /* ���^���h�� */ 

    if ( j == 0 )                    /* �פ����   */ 
       sum = 1;
    else
       sum = j * factriol( j - 1 );  /* ���^�I�s   */ 
    return sum;
}
