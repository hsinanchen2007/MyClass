/*   �{���W�� : ch4_26.c                  */
/*   �C�X���Z���G�ΨD����                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int co90,co80,co70,co60,co_below60;
    int number,sum,score;
    int i;
    float ave;

    co90 = co80 = co70 = co60 = co_below60 = sum = 0;
    printf("�п�J�ǥͤH�� ==> ");
    scanf("%d",&number);

    for ( i = 1; i <= number; i++ )
    {
       printf("�п�J�ǥͦ��Z %d ==> ",i);
       scanf("%d",&score);
       sum += score;
       if ( score >= 90 )
	      co90++;
       else if ( score >= 80 )
	      co80++;
       else if ( score >= 70 )
	      co70++;
       else if ( score >= 60 )
	      co60++;
       else
	      co_below60++;
    }
    ave = (float) sum / ( float ) number;
    printf("%d �Ӿǥͦ��Z�j�� 90 \n",co90);
    printf("%d �Ӿǥͦ��Z���� 80 - 90\n",co80);
    printf("%d �Ӿǥͦ��Z���� 70 - 80\n",co70);
    printf("%d �Ӿǥͦ��Z���� 60 - 70\n",co60);
    printf("%d �Ӿǥͦ��Z�p�� 60   \n",co_below60);
    printf("�����O %6.2f\n",ave);
    system("pause");
    return 0;
}
