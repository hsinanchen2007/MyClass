/*   �{���W�� : ch9_13.c                  */
/*   �p��g�~                             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum week { SUN, MON, TUE, WED, THR, FRI, SAT };
    enum week day;
    int  total, pay, hour;

    total = 0;
    printf("�п�J�g��ܶg�����u�@�ɼ� \n");
    for ( day = SUN; day <= SAT; day++ )
    {
       scanf("%d",&hour);
       switch ( day )
       {
          case SUN : pay = hour * 120; /* �g�� */ 
                     break;
          case SAT : pay = hour * 100; /* �g�� */ 
                     break;
          default  : pay = hour * 80;  /* �g�@�ܶg�� */
                     break;
       }
       total += pay;
    }
    printf("�g�~�O : %d\n",total);
    system("pause");
    return 0;
}
