#include <stdio.h>
void change(int *value);
int main()
{
    // ����: Ҫ����һ������, �ں������޸Ĵ���Ļ����������ͱ�����ֵ
    int num = 123;
    printf("num = %i\n", num);
    change(&num);
    printf("num = %i\n", num);
    return 0;
}
void change(int *value){
    *value = 666;
}
