/*   �{���W�� : ch3_16.c                  */
/*   scanf �M printf ����                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,k,sum;
    char ch1,ch2;
    float x1,x2,ave;

    printf("�п�J 2 �Ӧr�� \n==>");
    scanf("%c%c",&ch1,&ch2);
    printf("2 �Ӧr�����ۤϿ�X�O \n==>");
    printf("%c%c\n",ch2,ch1);
    printf("�п�J 3 �Ӿ�� \n==>");
    scanf("%d %d %d",&i,&j,&k);
    sum = i + j + k;
    printf("�`�M�O ==> %d\n",sum);
    printf("�п�J 2 �ӯB�I�� \n==>");
    scanf("%f %f",&x1,&x2);
    ave = ( x1 + x2 ) / 2.0;
    printf("�����O ==> %6.2f\n",ave);
    system("pause");
    return 0; 
}
