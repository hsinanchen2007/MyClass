#include <stdio.h>

int main()
{
    /*
     * 自增自减运算符
     * 自增 ++
     * 作用: 让变量中存储的值+1
     * 自减 --
     * 作用: 让变量中存储的值-1
     */

    // 需求: 给变量中存储的数据+1
    int num = 1;
    // 利用算数运算符
//    num = num + 1;
    // 利用赋值运算符
//    num += 1; // num = num + 1;
//    num++;
    num--;
    printf("num = %i\n", num);
    return 0;
}
