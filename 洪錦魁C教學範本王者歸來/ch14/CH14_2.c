/*   �{���W�� : ch14_2.c                  */
/*   �R���ɮ�                             */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i;

    for ( i = 1; i < argc; i++ )
      unlink(argv[i]);
    system("pause");
    return 0;  
}
