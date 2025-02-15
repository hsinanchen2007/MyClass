#include <stdio.h>

int main()
{
    // 计算1 + 2 + 3 + ...n的和
    // 计算1 + 2 + 3 + 4 的和
    /*
     * 规律:
     * 1.每一次都是用上一次的和, 加上当前的一个数
     * 2.每次被加上的这个数, 是从1开始递增的
        1 + 2 + 3 + 4
    0 + 1
        1 + 2
            3 + 3
                6 + 4
                    10
     */
    // 1.定义变量保存每次相加的和
    int sum = 0;
    // 2.定义变量保存每次被加上的数
    int num = 1;
    /*
    // 3.用上一次的和和当前被加上的数相加, 将相加的结果保存到和当中
    sum = sum + num; // sum = 0 + 1;
    num++; // 2

    sum = sum + num; // sum = 1 + 2;
    num++;

    sum = sum + num; // sum = 3 + 3;
    num++;

    sum = sum + num; // sum = 6 + 4;
    num++;
    */

    // 1.先编写循环的固定格式
    // 2.将重复执行的代码, 拷贝到{}中
    // 3.确定循环结束的条件
    // 1 + 2 + 3 + 4 + 5 = 15
    while(num <= 5){
        sum = sum + num; // sum = 0 + 1;
        num++; // 2
    }

    printf("sum = %i\n", sum);
    return 0;
}
