/*   �{���W�� : ch6_13.c                  */
/*   �C�L�ۤϦr�������j�������           */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 5;     /* �]�w��J 5 �Ӧr�� */ 
    void palindrom(int n);

    palindrom(i);
    printf("\n");
    system("pause");
    return 0;
}
void palindrom(n)
int n;
{
    char next;

    if ( n <= 1 ) /* Ū��̫᣸�Ӧr��������|����  */ 
    {
       next = getche();
       printf("\n");
       putchar(next);
    }
    else
    {
       next = getche();   /* Ū�r��   */ 
       palindrom(n-1);    /* �I�s�ۤv */ 
       putchar(next);
    }
}
