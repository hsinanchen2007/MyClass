
#include <stdio.h>

//想交换，但是交换的是里面的x,y，和外面的没关系
void swap(int x, int y)
{
    int t = x;
    x = y;
    y = t; 

    printf("函数内部 x   %d   ,  y  %d\n", x, y);
}


void swap2(int * pA, int *pB)
{
    int t = *pA;
    *pA= *pB;
    *pB = t; 
}

int main()
{
    int a = 111;
    int b = 222;

    swap(a, b);

    printf("交换后a   %d   ,  b  %d\n", a, b);

    swap2(&a, &b);

    printf("交换后a   %d   ,  b  %d\n", a, b);


}
