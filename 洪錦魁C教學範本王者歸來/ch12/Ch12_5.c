/*   �{���W�� : ch12_5.c                  */
/*   ���� isdigit() ���                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    ch = getche();
    if ( isdigit(ch) )
    {
       putchar(ch);     /* �C�L�Ʀr */ 
       printf("\n");
    }
    system("pause");
    return 0;
}
