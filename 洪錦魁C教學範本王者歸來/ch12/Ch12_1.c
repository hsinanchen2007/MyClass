/*   �{���W�� : ch12_1.c                  */
/*   �p��^��r���P���ԧB�Ʀr���Ӽ�       */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    char ch;
    printf("�п�J���N�^��r���μƦr\n"); 
    while ( ( ch = getche() ) != '\r' )
       isalnum(ch) ? (count++) : ( count=count );
    printf("\n");   
    printf("�^��r���P���ԧB�Ʀr���Ӽ� = %d\n",count);
    system("pause");
    return 0;
}
