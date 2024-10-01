#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int* p1 = (int*)(&a + 1); 
    int* p2 = (int*)((int)a + 1);
    int* p3 = (int*)(a + 1);
    
    // 00CFFD48, 00CFFD48, 00CFFD5C
    // 00CFFD48 == 1
    // 00CFFD4C == 2
    // 00CFFD50 == 3
    // 00CFFD54 == 4
    // 00CFFD58 == 5
    // 00CFFD5C == 0
    // so although a is an array, &a is the address of the array
    // and &a + 1 is the address of the next memory block after the array
    printf("%p, %p, %p\n", a, &a, &a + 1);

    // p2 address is p1 address + 1
    printf("%p\n", p2);

    printf("%d, %d, %d\n", p1[-1], p2[0], p3[1]);
    
    return 0;
}
// A. 数组下标不能是负数，程序无法运行
// B. p1[-1]将输出随机数，p2[0]输出2， p3[1]输出3
// C. p1[-1]将输出乱码， p2[0]和p3[1]输出2
