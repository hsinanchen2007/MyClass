/*   �{���W�� : ch9_9.c                   */
/*   �H��Ƥ覡�p�⥭�����Z               */
#include <stdio.h>
#include <stdlib.h>
void sum(int i, int j, int k, int index)
{
    static int sum1 = 0;
    static int sum2 = 0;
    static int sum3 = 0;
    sum1 += i;
    sum2 += j;
    sum3 += k;
    if ( index == 4 ) /* �p�⧹�̫᣸�Ӥ����D���� */ 
    {
       printf("�ƾǥ��� ==> %5.2f\n",sum1/5.0);
       printf("�^�奭�� ==> %5.2f\n",sum2/5.0);
       printf("�q�⥭�� ==> %5.2f\n",sum3/5.0);
    }
}
int main()
{
    struct score        /* �w�q���c��ƦW�� */
    {
       int   math;      /* �ƾ� */
       int   engl;      /* �^�� */
       int   comp;      /* �q�� */
    } ;
    struct score test[5] = {  /* �����]�w���c�}�C���e */
           { 74, 80, 66 },
           { 72, 90, 77 },
           { 77, 65, 60 },
           { 65, 58, 74 },
           { 81, 79, 68 } };
    int i;

    for ( i = 0; i < 5; i++ )
       sum(test[i].math,test[i].engl,test[i].comp,i);
    system("pause");
    return 0;
}
