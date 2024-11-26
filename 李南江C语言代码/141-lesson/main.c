#include <stdio.h>
void say();
int minus(int a, int b);
int sum(int a, int b);
char* test();
int main()
{
    // 需求: 定义指针指向下列函数
    void (*p1)();
    p1 = say;
    p1();

    int (*p2)(int a, int b);
    p2 = minus;
    int res = p2(10, 20);
    printf("res = %i\n", res);

//    int (*p3)(int a, int b);
//    p3 = sum;
//    int res2 = p3(10, 20);
//    printf("res2 = %i\n", res2);

    p2 = sum;
    int res2 = p2(10, 20);
    printf("res2 = %i\n", res2);


    char* (*p4)();
    p4 = test;
    char *res3 = p4();
    printf("res3 = %s\n", res3);
    return 0;
}
void say(){
    printf("hello world\n");
}
int minus(int a, int b){
    return a - b;
}
int sum(int a, int b){
    return a +b;
}
char* test(){
    char *name = "lnj";
    return name;
}
