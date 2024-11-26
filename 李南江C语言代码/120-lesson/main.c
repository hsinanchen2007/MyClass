#include <stdio.h>
void change(int values[2][3]);
void change2(int values[3]);
int main()
{
    /*
     * 1.基本数据类型和函数
     * 在函数内修改形参, 不会影响到外界实参
     *
     * 2.一维数组和函数
     * 在函数内修改形参, 会影响到外界实参
     *
     * 3.二维数组和函数
     * 在函数内修改形参, 会影响到外界实参
     *
     * 总结:
     * 以后要想知道在函数中修改形参会不会影响到外界的实参, 是不是看一下传递的是不是地址就可以了
     * 如果传递的是地址, 那么在函数内修改形参, 会影响到外界实参
     */
    int nums[2][3] = {
        {1, 3, 5},
        {2, 4, 6}
    };
//    printf("nums[0][1] = %i\n", nums[0][1]);
//    change(nums);
//    printf("nums[0][1] = %i\n", nums[0][1]);

//    printf("&nums[0] = %p\n", &nums[0]);
//    printf("nums[0] = %p\n", nums[0]);

    printf("nums[0][1] = %i\n", nums[0][1]);
    change2(nums[0]);
    printf("nums[0][1] = %i\n", nums[0][1]);
    return 0;
}
void change2(int values[3]){
    values[1] = 777;
}

void change(int values[2][3]){
    values[0][1] = 666;
}
