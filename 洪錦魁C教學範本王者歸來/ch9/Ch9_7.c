/*   �{���W�� : ch9_7.c                   */
/*   ���c�}�C������                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score        /* �w�q���c��ƦW�� */
    {
       int   math;      /* �ƾ� */
       int   english;   /* �^�� */
       int   computer;  /* �q�� */
    } ;
    struct score test[5] = { /* �����]�w���c�}�C���e */ 
           { 74, 80, 66 },
           { 72, 90, 77 },
           { 77, 65, 60 },
           { 65, 58, 74 },
           { 81, 79, 68 } };
    int i,sum1,sum2,sum3;
    float ave1, ave2, ave3;

    sum1 = sum2 = sum3 = 0;
    for ( i = 0; i < 5; i++ )    /* �p��U�즨�Z�`�M */ 
    {
       sum1 += test[i].math;
       sum2 += test[i].english;
       sum3 += test[i].computer;
    }
    ave1 = (float) sum1 / 5.0;   /* �D�ƾǥ��� */ 
    ave2 = (float) sum2 / 5.0;   /* �D�^�奭�� */ 
    ave3 = (float) sum3 / 5.0;   /* �D�q������ */ 
    printf("�ƾǥ��� ==> %8.3f\n",ave1);
    printf("�^�奭�� ==> %8.3f\n",ave2);
    printf("�q������ ==> %8.3f\n",ave3);
    system("pause");
    return 0;
}
