/*   �{���W�� : ch9_3.c                   */
/*   �� struct ���� 2                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score      /* �w�q���c��ƦW�� */
    {
       int math;      /* �ƾ� */
       int english;   /* �^�� */
       int computer;  /* �q�� */
    };
    struct score hung, chen;  /* �w�q�ܼ� */

    hung.math = 80;
    hung.english = 85;
    hung.computer = 83;
    chen.math = 75;
    chen.english = 91;
    chen.computer = 88;
    printf("�m�W      �ƾ�     �^��     �q�� \n");
    printf("�x���X     %d       %d       %d   \n",
            hung.math,hung.english,hung.computer);
    printf("������     %d       %d       %d   \n",
            chen.math,chen.english,chen.computer);
    system("pause");
    return 0;
}
