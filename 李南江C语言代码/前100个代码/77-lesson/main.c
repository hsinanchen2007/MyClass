#include <stdio.h>

int getAge(){
    return 18;
}
int getSum(int a, int b){
    int res = a + b;
    return res;
}
void say(int age){
    printf("age = %i\n", age);
}

int test1(){
    return 666;
}
float test2(){
    return 1.11;
}
double test3(){
    return 3.14;
}
char test4(){
    return 'a';
}
int main()
{
    // 1.�����������β�, Ҳ����û���β�
//    getAge();
//    getSum(10, 20);
    // 2.�������βο������������
//    say(18);
    // 3.���������з���ֵ, Ҳ����û�з���ֵ
    // 4.�������û�з���ֵ, ��ô�����ķ���ֵ�����Ƽ���дvoid
    // 5.�����ķ���ֵ����, ������C�����е���������
    printf("%i\n", test1());
    printf("%f\n", test2());
    printf("%lf\n", test3());
    printf("%c\n", test4());
    return 0;
}
