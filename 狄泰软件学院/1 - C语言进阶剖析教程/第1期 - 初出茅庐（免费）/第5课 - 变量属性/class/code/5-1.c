#include <stdio.h>

int f1()
{
    int r = 0;
    
    r++;
    
    return r;
}

int f2()
{
    static int r = 0;
    
    r++;
    
    return r;
}

int main()
{
    auto int i = 0;       // ��ʾ���� auto ���ԣ�i Ϊջ����
    static int k = 0;     // �ֲ����� k �Ĵ洢��λ�ھ�̬����������λ�� main ��
    register int j = 0;   // ����������뽫 j �洢�ڼĴ�����

    printf("%p\n", &i);
    printf("%p\n", &k);
    // printf("%p\n", &j);   // error
    
    for(i=0; i<5; i++)
    {
        printf("%d\n", f1());
    }
    
    for(i=0; i<5; i++)
    {
        printf("%d\n", f2());
    }
    
    return 0;
}