/*   �{���W�� : ch6_7.c                   */
/*   �D�̤j��, �̤p��, �M�D�`�M           */
#include <stdio.h>
#include <stdlib.h>
int min(x,y)
int x,y;
{
    if ( x <= y )
       return x;    /* �Ǧ^�̤p�ȬO x */ 
    else
       return y;    /* �Ǧ^�̤p�ȬO y */ 
}
int max(x,y)
int x,y;
{
    if ( x <= y )
       return y;    /* �Ǧ^�̤j�ȬO y */ 
    else
       return x;    /* �Ǧ^�̤j�ȬO x */ 
}
int main()
{
    int num,value,i;
    int tmpmax = -1000;     /* �ȩw�̤j�� */ 
    int tmpmin = 1000;      /* �ȩw�̤p�� */ 
    int sum = 0;

    printf("�п�J��Ƽƥ� ==> ");
    scanf("%d",&num);
    for ( i = 1; i <= num; i++ )
    {
       printf("�п�J�ƭ� %d ==> ",i);
       scanf("%d",&value);
       tmpmin = min(value,tmpmin); /* ��̤p�� */ 
       tmpmax = max(value,tmpmax); /* ��̤j�� */ 
       sum += value;               /* �D�`�M   */ 
    }
    printf("�̤j�� %d \n",tmpmax);
    printf("�̤p�� %d \n",tmpmin);
    printf("�`�M %d \n",sum);
    system("pause");
    return 0;
}
