#include <stdio.h>
void swap(int *p1, int *p2);
int main()
{
    // ����: ���庯����������������ֵ
    int a = 10;
    int b = 20;
    printf("a = %i, b = %i\n", a, b);
    swap(&a, &b);
    printf("a = %i, b = %i\n", a, b);
    return 0;
}
void swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
