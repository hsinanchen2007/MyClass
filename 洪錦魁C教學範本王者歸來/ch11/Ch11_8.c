/*   �{���W�� : ch11_8.c                  */
/*   ~ ( 1 ���ɼ� ) �B��                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 234;
    b = ~a;
    printf("a �� 1 �ɼ� ( 10 �i��) = %d \n",b);
    a = ~a;
    printf("a �� 1 �ɼ� ( 16 �i��) = %x \n",a);
    system("pause");
    return 0;
}
