#include <stdio.h>
int getMax(int values[5], int len);
int main()
{
    // 需求: 定义一个函数, 获取数组中的最大值
    int nums[5] = {3, 2, 1, 5, 4};
    // 1.定义变量保存最大值
//    int max = nums[0]; // 假设第0个元素就是最大值
    // 2.遍历数组, 取出所有元素
    int len = sizeof(nums) / sizeof(nums[0]);
//    for(int i = 1; i < len ; i++){
//        // 3.利用当前遍历到的元素和最大值进行比较
//        if(nums[i] > max){
//            // 4.将最大值修改为当前的元素
//            max = nums[i];
//        }
//    }
    int max = getMax(nums, len);
    // 5.输出结果
    printf("max = %i\n", max);
    return 0;
}

int getMax(int values[5], int len){
    // 1.定义变量保存最大值
    int max = values[0]; // 假设第0个元素就是最大值
    // 2.遍历数组, 取出所有元素
    for(int i = 1; i < len ; i++){
        // 3.利用当前遍历到的元素和最大值进行比较
        if(values[i] > max){
            // 4.将最大值修改为当前的元素
            max = values[i];
        }
    }
    // 5.返回最大值
    return max;

}
