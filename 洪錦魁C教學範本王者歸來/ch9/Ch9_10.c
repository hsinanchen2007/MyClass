/*   �{���W�� : ch9_10.c                  */
/*   �ŧi�~�b���c�ǻ����c�ܨ��           */
#include <stdio.h>
#include <stdlib.h>
struct score     /* �w�q���c��ƦW�� */
{
    int  math;   /* �ƾ� */
    int  engl;   /* �^�� */
    int  comp;   /* �q�� */
};
void sum(struct score sc, int index)
{
    static int sum1 = 0;
    static int sum2 = 0;
    static int sum3 = 0;
    sum1 += sc.math;
    sum2 += sc.engl;
    sum3 += sc.comp;
    if ( index == 4 )   /* Ū���̫᣸����ƫh�D���� */
    {
       printf("�ƾǥ��� ==> %5.2f\n",sum1/5.0);
       printf("�^�奭�� ==> %5.2f\n",sum2/5.0);
       printf("�q�⥭�� ==> %5.2f\n",sum3/5.0);
    }
}
int main()
{
    struct score test[5];
    int i;

    printf("�п�J�U�C���� \n");
    printf("�ƾ� �^�� �q��\n");
    for ( i = 0; i < 5; i++ )
    {
       scanf("%d%d%d",&test[i].math,&test[i].engl,&test[i].comp);
       sum(test[i],i);
    }
    system("pause");
    return 0;
}
