/*   �{���W�� : ch14_3.c                  */
/*   ����ɮצW��                         */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i;

    if ( argc != 3 )
       printf("��J���~ \n");
    rename(argv[1],argv[2]);    
    system("pause");
    return 0;  
}
