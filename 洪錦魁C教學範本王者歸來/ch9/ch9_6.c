/*   �{���W�� : ch9_6.c                   */
/*   struct ��ȳ]�w                      */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score        /* �w�q���c��ƦW�� */
    {
       int   math;      /* �ƾ� */
       int   english;   /* �^�� */
       int   computer;  /* �q�� */
       char  sex;       /* �ʧO */ 
    } ;             
    struct score wa = { 80, 85, 83, 'M' };

    printf("�m�W    �ʧO  �ƾ�  �^��  �q��  \n");
    printf("������   %c     %d    %d    %d   \n",
            wa.sex,wa.math,wa.english,wa.computer);
    system("pause");
    return 0;
}
