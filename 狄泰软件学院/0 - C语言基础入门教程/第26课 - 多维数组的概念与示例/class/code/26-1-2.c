#include <stdio.h>

int main()
{
    int a[][3] = { {1, 2, 3}, {4, 5} };
    int s1 = sizeof(a) / sizeof(a[0]);  // 2
    int i = 0;
    int j = 0;

    printf("s1 = %d\n", s1);
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(a[0]) = %d\n", sizeof(a[0])); // int[3]

    for(i=0; i<s1; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);  // �����������Կ�������
                                                        // ��ˣ�����ʹ�� 2 ���±���ʾ����е�ֵ
        }
    }

    return 0;
}
