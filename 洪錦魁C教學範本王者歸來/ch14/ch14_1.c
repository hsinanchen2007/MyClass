/*   �{���W�� : ch14_1.c                  */
/*   �R���ɮ�                             */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i;

    for ( i = 1; i < argc; i++ )
      remove(argv[i]);
    system("pause");
    return 0;  
}
