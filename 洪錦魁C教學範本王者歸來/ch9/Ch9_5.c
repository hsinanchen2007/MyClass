/*   �{���W�� : ch9_5.c                   */
/*   �� struct ���]�t���P��ƫ��A       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score        /* �w�q���c��ƦW�� */
    {
       int   math;      /* �ƾ� */
       int   english;   /* �^�� */
       int   computer;  /* �q�� */
       float ave;       /* ���� */ 
       char  sex;       /* �ʧO */ 
    } wa;             /* �����w�q�ܼ� */

    wa.math = 80;
    wa.english = 85;
    wa.computer = 83;
    wa.ave = (float) (wa.math+wa.english+wa.computer) / 3.0;
    wa.sex = 'M';
    printf("�m�W    �ʧO  �ƾ�  �^��  �q��  ���� \n");
    printf("������   %c     %d    %d    %d   %5.2f \n",
            wa.sex,wa.math,wa.english,wa.computer,wa.ave);
    system("pause");
    return 0;
}
