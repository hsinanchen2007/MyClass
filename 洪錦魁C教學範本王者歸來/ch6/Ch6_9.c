/*   �{���W�� : ch6_9.c                   */
/*   �D�}�C�̤p��                         */
#include <stdio.h>
#include <stdlib.h>
int minimum(var)
int var[5];
{
    int min,i;

    min = var[0]; /* �ȩw�}�C�Ĥ@�Ӥ����O�̤p�� */ 
    for ( i = 0; i <= 4; i++ )
       if ( var[i] < min )  /* �Y��̤p�Ȥp   */ 
          min = var[i];     /* �]�w�s���̤p�� */ 
    return min;             /* �Ǧ^�̤p��     */ 
}
int main()
{
    int array[5];
    int minimum_value;
    int i;

    for ( i = 0; i < 5; i++ )  /* Ū���}�C�� */ 
    {
       printf("�п�J�ƭ� %d ==> ",i+1);
       scanf("%d",&array[i]);
    }
    minimum_value = minimum(array);
    printf("�̤p�ȬO %d \n",minimum_value);
    system("pause");
    return 0;
}
