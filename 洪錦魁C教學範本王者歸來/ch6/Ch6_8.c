/*   �{���W�� : ch6_8.c                   */
/*   �D������                             */
#include <stdio.h>
#include <stdlib.h>
float avg(var,num)
int var[];
int num;
{
    float ave = 0.0;
    int i;

    for ( i = 0; i < num; i++ )
       ave += var[i];      /* �D�`�M   */ 
    ave /= (float) num;    /* �D����   */ 
    return ave;            /* �Ǧ^���� */ 
}
int main()
{
    int array[5];
    float average;
    int i;

    for ( i = 0; i < 5; i++ )
    {
       printf("�п�J�ƭ� %d ==> ",i+1);
       scanf("%d",&array[i]);
    }
    average = avg(array,5);
    printf("�����ȬO %6.2f \n",average);
    system("pause");
    return 0;
}
