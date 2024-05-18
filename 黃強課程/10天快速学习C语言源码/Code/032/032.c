 
#include <stdio.h>

int main()
{
    int* p = NULL;//既然p是变量，那么就占内存，就有地址

    printf("指针变量p的地址 %p\n", &p);

    //定义指针的指针
    int** pp = &p;

    //定义指针的指针的指针
    int** ppp = &pp;

    printf("p变量的地址是%p\n", &p);
    printf("pp变量的内容是%p\n", pp);

    printf("pp变量的地址是%p\n", &pp);
    printf("ppp变量的内容是%p\n", ppp);

}
 