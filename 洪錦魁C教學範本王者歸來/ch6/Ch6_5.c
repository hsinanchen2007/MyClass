/*   �{���W�� : ch6_5.c                   */
/*   �r���C�L��Ʃ�b�D�{���᭱           */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    void print_char();

    for ( i = 0; i < 5; i++ )
       print_char('A');
    system("pause");
    return 0;   
}
void print_char(c)
char c;
{
    printf("%c\n",c);
}
