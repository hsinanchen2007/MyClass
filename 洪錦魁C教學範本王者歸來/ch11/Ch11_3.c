/*   �{���W�� : ch11_3.c                  */
/*   &  ( AND )�줸�B��                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 077;
    b = a & 3;
    printf("a & b (10 �i��) = %d \n",b);
    b &= 7;
    printf("a & b (10 �i��) = %d \n",b);
    system("pause");
    return 0;
}
