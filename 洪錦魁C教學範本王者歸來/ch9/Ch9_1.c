/*   �{���W�� : ch9_1.c                   */
/*   ��J�ؤ�ūץ��{���N��X���ū�     */
#include <stdio.h>
#include <stdlib.h>
typedef   float   tmp;
int main()
{
    tmp  f,c;

    printf("��J�ؤ�ū� \n==> ");
    scanf("%f",&f);
    c = ( 5.0 / 9.0 ) * ( f - 32.0 );
    printf("��X���ū� %6.2f \n",c);
    system("pause");
    return 0;
}
