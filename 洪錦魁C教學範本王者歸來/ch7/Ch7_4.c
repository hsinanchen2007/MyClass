/*   �{���W�� : ch7_4.c                   */
/*   �D�}�C�̤j�Ȩ��                     */
#include <stdio.h>
#include <stdlib.h>
int maximum( int var[], int number )
{
    int max, i;
    max = var[0];           /* �ȩw�}�C�Ĥ@�ӭȬ��̤j�� */ 
    for ( i = 0; i < number; i++ )
    {
       if ( var[i] > max )  /* �p�G�}�C�Ȥj��ȩw�̤j�� */ 
          max = var[i];     /* �]�w�s���̤j�� */ 
    }
    return max;
}
int main()
{
    static int array1[5] = { 134, 211, 122, 333, 237 };
    static int array2[4] = { 132, 123, 37, 98 };

    printf("�}�C array1 �̤j�ȬO %d \n",maximum(array1,5));
    printf("�}�C array2 �̤j�ȬO %d \n",maximum(array2,4));
    system("pause");
    return 0;
}
