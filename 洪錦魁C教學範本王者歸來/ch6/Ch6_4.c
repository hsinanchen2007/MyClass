/*   �{���W�� : ch6_4.c                   */
/*   �]�p�r���C�L���                     */
#include <stdio.h>
#include <stdlib.h>
void print_char(c)
char c;
{
    printf("%c\n",c);
}
int main()
{
    int i;
    for ( i = 0; i < 5; i++ )
       print_char('A');
    system("pause");
    return 0;   
}
