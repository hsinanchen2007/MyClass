/*   �{���W�� : ch6_14.c                  */
/*   ���{���|�C�X��J�Ʀr���r����� a     */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    void draw();
    int j;

    printf("�п�J�r����� ==> ");
    scanf("%d",&j);
    draw(j);
    system("pause");
    return 0;
}
void draw(int n)
{
    int i;
/* �U�C�j���i�C�X��J���ת��r�� */ 
    for ( i = 1; i <= n; i++ ) 
       printf("a");
    printf("\n");
}
