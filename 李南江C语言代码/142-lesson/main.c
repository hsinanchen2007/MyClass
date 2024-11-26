#include <stdio.h>
int minus(int a, int b);
int sum(int a, int b);
int calculate(int a, int b, int (*fn)(int a, int b));
int main()
{
    // ����: ����һ������, ���ú������غ�ʱ�ͷ��غ�, ���ú������ز�ʱ�ͷ��ز�
    /*
    int (*fn)(int a, int b);
    fn = minus;
    // ��ǰfnָ��ָ����minus����, ���Ե��õľ���Minus����
    int res = fn(10, 20);
    printf("res = %i\n", res);

    fn = sum;
    // ��ǰfnָ��ָ����sum����, ���Ե��õľ���Sum����
    int res2 = fn(10, 20);
    printf("res2 = %i\n", res2);
    // ����: ָ�����ָ��˭, ���õľ���˭
    */
//    int res = calculate(10, 20, minus);
    int res = calculate(10, 20, sum);
    printf("res = %i\n", res);
    return 0;
}

int calculate(int a, int b, int (*fn)(int a, int b)){
    return fn(a, b);
}

int minus(int a, int b){
    return a - b;
}
int sum(int a, int b){
    return a + b;
}
