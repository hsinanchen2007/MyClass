#include <stdio.h>

int global;

int func(int x)
{
    static int s_var;   // ȫ���������еı�����Ĭ�ϳ�ʼ��Ϊ 0
                        // ���ң�ֻ��һ�γ�ʼ��
    s_var += x;

    return s_var;
}

int main()
{
    int i = 0;

    for(i=1; i<=5; i++)
    {
        printf("func(%d) = %d\n", i, func(i));
    }

    printf("func(0) = %d\n", func(0));

    printf("global = %d\n", global);

    return 0;
}
