#include <stdio.h>

int main()
{
    /*
     * 1.二维数组的存储细节
     * 和一维数组一模一样
     * 1.1分配存储空间从内存地址大的开始分配
     * 1.2数组名对应的是占用存储空间最小的地址
     * 1.3给元素分配存储空间从占用存储空间内存地址小的开始分配
     */
    char chs[2][3] = {
        {'l', 'n', 'j'},
        {'i', 't', '6'}
    };
    printf("chs = %p\n", chs);
    printf("&chs = %p\n", &chs);
    printf("&chs[0] = %p\n", &chs[0]);
    printf("&chs[0][0] = %p\n", &chs[0][0]);
    return 0;
}
