/*   �{���W�� : ch9_8.c                   */
/*   �_�����c������                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct grade        /* ���h���c */ 
    {
       int   score;     /* ���� */ 
       char  grade;     /* ���Z */ 
    };
    struct score        /* �~�h���c */ 
    {
       struct grade  math;
       struct grade  english;
       struct grade  computer;
    } hung;

    hung.math.score = 92;
    hung.math.grade = 'A';
    hung.english.score = 85;
    hung.english.grade = 'B';
    hung.computer.score = 88;
    hung.computer.grade = 'B';
    printf("�ƾǤ��� ==> %d\n",hung.math.score);
    printf("�ƾǦ��Z ==> %c\n",hung.math.grade);
    printf("�^����� ==> %d\n",hung.english.score);
    printf("�^�妨�Z ==> %c\n",hung.english.grade);
    printf("�q����� ==> %d\n",hung.computer.score);
    printf("�q�⦨�Z ==> %c\n",hung.computer.grade);
    system("pause");
    return 0;
} 
