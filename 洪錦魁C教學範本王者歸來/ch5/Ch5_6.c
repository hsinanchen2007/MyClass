/*   �{���W�� : ch5_6.c                   */
/*   �G���}�C���k                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num1[3][3],num2[3][3],num3[3][3];
    int i,j,tmp;

    printf("�п�J�Ĥ@�ӤG���}�C \n");
    for ( i = 0; i < 3; i++ )
       for ( j = 0; j < 3; j++ )
          scanf("%d",&num1[i][j]);
    printf("�п�J�ĤG�ӤG���}�C \n");
    for ( i = 0; i < 3; i++ )
       for ( j = 0; j < 3; j++ )
          scanf("%d",&num2[i][j]);
    for ( i = 0; i < 3; i++ )     /* ����ۭ� */ 
       for ( j = 0; j < 3; j++ )
       {
          tmp = 0;
          tmp += num1[i][0] * num2[0][j];
          tmp += num1[i][1] * num2[1][j];
          tmp += num1[i][2] * num2[2][j];
          num3[i][j] = tmp;
       }
    printf("�C�X�ۭ����G \n");
    for ( i = 0; i < 3; i++ )
       printf("%3d %3d %3d\n",num3[i][0],num3[i][1],num3[i][2]);
    system("pause");
    return 0;
}
