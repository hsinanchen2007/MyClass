/*   �{���W�� : ch8_2.c                   */
/*   �t���� #define ����                  */
#include <stdio.h>
#include <stdlib.h>
#define   PI   3.1415926    /* �w�q��P�v */ 
#define   R    3.0          /* �w�q�b�|   */ 

int main()
{
    float  area,circle;

    area = PI * R * R;
    circle = 2 * PI * R;

    printf("�ꭱ�n = %8.4f\n",area);
    printf("��P�� = %8.4f\n",circle);
    system("pause");
    return 0;
}
