/*   �{���W�� : ch12_2.c                  */
/*   �p��^��r���Ӽ�                     */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    char ch;
    
    printf("�п�J���N�^��r���μƦr\n");
    while ( ( ch = getche() ) != '\r' )
       isalpha(ch) ? (count++) : ( count=count );
    printf("\n�^��r���Ӽ� = %d\n",count);
    system("pause");
    return 0;
}
