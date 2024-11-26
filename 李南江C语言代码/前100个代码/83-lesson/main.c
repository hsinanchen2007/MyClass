#include <stdio.h>

int pow(int base, int n);
int main()
{
    /*
     * 需求: 设计一个函数用来计算B的n次方
     *
     * 3(0) = 1
     * 3(1) = 3
     * 3(2) = 3 * 3 = 9
     * 3(3) = 3 * 3 * 3 = 27
     *
     *
     * 3(0) = 1
     * 3(1) = 3(0) * 3 = 1 * 3 = 3
     * 3(2) = 3(1) * 3 = 3 * 3 = 9
     * 3(3) = 3(2) * 3 = 3 * 3 * 3 = 27
     *
     * 规律:
     * 3(n) = 3(n-1) * 3
     */
    int res  = pow(3, 3);
    printf("res = %i\n", res);
    return 0;
}

// pow函数的作用:
// 求base的n次方
int pow(int base, int n){
    if(n == 0){
        return 1;
    }else{
        return pow(base, n - 1) * base;
    }
}
