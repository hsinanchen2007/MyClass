/*   �{���W�� : ch2_1.c                   */
/*   �{�ѷ���Overflow                     */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    short int i, j, k;
    
    i = 32767;
    j = i + 1;
    k = j - 1;
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("k = %d\n", k);
    system("pause");
    return 0;
}
