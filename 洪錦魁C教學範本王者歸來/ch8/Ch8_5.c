/*   �{���W�� : ch8_5.c                   */
/*   #define ���� 5                       */
#include <stdio.h>
#include <stdlib.h>
#define   BEGIN   {
#define   END     }

int main()
BEGIN
    int i;

    for ( i = 0; i < 3; i++ )
    BEGIN
       printf("���� Pascal begin �M end.\n");
       printf("BEGIN �O { \n");
       printf("END   �O } \n");
    END
    system("pause");
    return 0;
END
