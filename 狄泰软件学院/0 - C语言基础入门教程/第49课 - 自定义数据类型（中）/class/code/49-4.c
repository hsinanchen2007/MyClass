#include <stdio.h>
#include <string.h>

struct BW
{
    unsigned char a : 4;
    unsigned char b : 2;
    unsigned char c : 2;
};

int main()
{
    struct BW bw = {0};

    bw.a = 10;
    bw.b = 4;   // 4 ���� b �ܱ�ʾ�����ֵ����˸�ֵ�� b ��ת�� 0
    bw.c = 3;

    printf("sizeof(struct BW) = %d\n", sizeof(struct BW));
    printf("bw.a = %d\n", bw.a);
    printf("bw.b = %d\n", bw.b);
    printf("bw.c = %d\n", bw.c);

    return 0;
}

