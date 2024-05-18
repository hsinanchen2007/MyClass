
#include <stdio.h>

int main()
{
    char a; //定义一个字符型变量，它的内存地址是 &a
    char* pA = &a;// 把4字节的地址值赋给 指针变量pA

    printf("变量a的地址是 %p\n", &a);
    printf("变量pA的值是 %p\n", pA);

    int   b;//定义整型变量b，它的内存地址是&b
    int* pB = &b;// 把4字节的地址值赋给 指针变量pB

    printf("变量b的地址是 %p\n", &b);
    printf("变量pB的值是 %p\n", pB);

    //如果指针变量不赋值，就是野指针
    int* p=NULL;//一般建议初始化为NULL
    printf("NULL的值 %p\n", p);


    //通过 *指针变量，可以操作该指针指向内存上的内容
    int  c = 100;
    printf("变量c的值是 %d\n", c);
    int* pC = &c;// 把4字节的C的地址值赋给 指针变量pC
   
    *pC = 200;//操作该指针指向内存上的内容
    printf("变量c的值通过指针被篡改了 %d\n", c);

}
