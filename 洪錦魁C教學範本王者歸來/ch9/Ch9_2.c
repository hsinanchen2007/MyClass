/*   �{���W�� : ch9_2.c                   */
/*   �� struct ������                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score     /* �w�q���c��ƦW�� */ 
    {
       int math;     /* �ƾ� */ 
       int english;  /* �^�� */ 
       int computer; /* �q�� */ 
    };
    struct score hung;  /* �w�q�ܼ� */ 

    hung.math = 80;
    hung.english = 85;
    hung.computer = 83;
    printf("�m�W      �ƾ�     �^��     �q�� \n");
    printf("�x���X     %d       %d       %d    \n",
            hung.math,hung.english,hung.computer);
    system("pause");
    return 0;
}
