#include <stdio.h>


// ��������
//int getSum(int, int);
//int getSum(int, int);
//int getSum(int, int);
//int getSum(int, int);
//int getSum(int, int);
int main()
{

    // 1.���������е��βα������ƿ��Բ�д
    // 2.�����Ķ��岻�����ظ�, ���Ǻ��������������ظ�
    // 3.����������ֻҪ�ڵ���֮ǰ��������
    int getSum(int, int);
    int num = getSum(10, 20);
    printf("num = %i\n", num);
    return 0;
}
// �����Ķ���
int getSum(int a, int b){
    int res = a + b;
    return res;
}



