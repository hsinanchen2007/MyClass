/*   �{���W�� : ch11_2.c                  */
/*   &  ( AND )�줸�B��                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned int  a, b;

    a = 077;     /* 0 �}�l�ҥH�O 8 �i��Ʀr */
    b = 0150;    /* 0 �}�l�ҥH�O 8 �i��Ʀr */
    printf("a & b (10 �i��) = %d \n",a&b);
    printf("a & b (8 �i�� ) = %o \n",a&b);
    system("pause");
    return 0;
}
