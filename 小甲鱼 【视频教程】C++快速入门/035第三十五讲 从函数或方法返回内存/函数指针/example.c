#include <stdio.h>

int fun(int x, int y);

int main()
{
        int i,a,b;
        int (*p)();    /* ��������ָ�� */

        scanf("%d",&a);
        p = fun;            /* ������ָ��p��ֵ,ʹ��ָ����f */

        printf("�������Ǹ�����: \n");
        for(i=0; i < 10; i++)
        {
                scanf("%d", &b);
                a = (*p)(a, b);    /* ͨ��ָ��p���ú���f */
        }

        printf("The Max Number is:%d", a);

        return 0;
}

fun(int x, int y)
{
    int z;

    z = (x > y) ? x : y;

    return(z);
}
