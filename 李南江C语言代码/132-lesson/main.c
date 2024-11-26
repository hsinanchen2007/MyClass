#include <stdio.h>

int main()
{
    // 1.指针变量是专门用于保存其它变量的地址的, 不要使用指针变量来保存其它的数据
//    int num = 123;
//    int *p;
//    p = &num;
//    printf("*p = %i\n", *p);

//    int *p;
//    p = 666;
//    printf("*p = %i\n", *p);

    // 2.一个普通的变量, 可以被多个指针变量指向
//    int num = 123;
//    int *p1;
//    int *p2;
//    p1 = &num;
//    p2 = &num;

//    printf("num = %i\n", num);
//    *p1 = 666;
//    printf("num = %i\n", num);
//    *p2 = 777;
//    printf("num = %i\n", num);

    // 3.一个指针变量的指向是可以修改的
//    int num = 123;
//    int value = 666;
//    int *p;
//    p = &num;
//    printf("*p = %i\n", *p); // 123
//    p = &value;
//    printf("*p = %i\n", *p); // 666

    // 4.指针变量的类型必须和保存的普通变量的类型一致
    // 指针变量类型的作用:
    // 告诉操作系统, 访问指向存储空间的时候, 需要取出多少个字节的数据
    int num = 666; //0000 0000 0000 0000 0000 0010 1001 1010
//    int *p;
    char *p; // 1001 1010
    p = &num;
    printf("*p = %i\n", *p);
    return 0;
}

