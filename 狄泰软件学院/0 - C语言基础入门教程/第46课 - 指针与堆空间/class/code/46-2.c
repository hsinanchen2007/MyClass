#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = malloc(4); // �Ӷѿռ����� 4 ���ֽڵ��� int ���͵ı���ʹ��

    if( p != NULL )  // �������ʧ�� p Ϊ 0 ��������ֵ
    {
        *p = 100;

        printf("%d\n", *p);     // 100

        free(p);
    }

    p = malloc(4 * sizeof(int));

    if( p != NULL )
    {
        int i = 0;

        for(i=0; i<4; i++)
        {
            p[i] = i * 10;
        }

        // 0 10 20 30
        for(i=0; i<4; i++)
        {
            printf("%d\n", p[i]);
        }

        free(p);
    }

    return 0;
}
