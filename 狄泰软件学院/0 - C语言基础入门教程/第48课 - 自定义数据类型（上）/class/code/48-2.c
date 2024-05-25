#include <stdio.h>
#include <string.h>

typedef  float(FArr5)[5];        // 定义数组类型名
typedef  int(IFuncII)(int, int); // 定义函数类型名

typedef  FArr5*    PFArr5;
typedef  IFuncII*  PIFuncII;

float g_arr[5] = {0.1, 0.2, 0.3};

int add(int a, int b)
{
    return a + b;
}

int main()
{
    FArr5* pa = &g_arr;  // float(*)[5]
    IFuncII* pf = add;   // int(*)(int,int)

    PFArr5   npa = pa;
    PIFuncII npf = pf;

    int i = 0;

    for(i=0; i<5; i++)
    {
        printf("%f\n", (*pa)[i]);
        printf("%f\n", (*npa)[i]);
    }


    printf("%d\n", pf(2, 3));
    printf("%d\n", npf(2, 3));

    return 0;
}
