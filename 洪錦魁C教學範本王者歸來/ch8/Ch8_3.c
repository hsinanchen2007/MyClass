/*   �{���W�� : ch8_3.c                   */
/*   #define ���t��������                 */
#include <stdio.h>
#include <stdlib.h>
#define   TRUE   1
#define   FALSE  0
#define   SQ(x)  ( x * x )

int main()
{
    int num;
    int again = 1;

    printf("�p�G��J�p�� 50 �{���N�۰ʵ��� \n");
    while ( again )   /* �p�G�j��ε��� 50 �{���~�� */ 
    {
       printf("�п�J�ƭ� ==> ");
       scanf("%d",&num);
       printf("����ȬO = %d \n",SQ(num));
       if ( num >= 50 )      
          again = TRUE;
       else
          again = FALSE;  /* ��J�p�� 50 �h�]�w */ 
    }
    system("pause");
    return 0;
}
