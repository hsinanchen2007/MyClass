/*   �{���W�� : ch10_8.c                  */
/*   �����r���X                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char string[] = "Hello !";

    printf("/%s/\n",string);
    printf("/%2s/\n",string);
    printf("/%14s/\n",string);
    printf("/%-14s/\n",string);
    system("pause");
    return 0;
}
