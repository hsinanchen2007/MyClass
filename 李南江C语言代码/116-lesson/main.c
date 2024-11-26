#include <stdio.h>

int main()
{
    // 需求： 从有序数组中找出指定值的位置
    int nums[5] = {1, 3, 5, 7, 9};
    int key = -5;
//    for(int i = 0; i < 5; i++){
//        if(nums[i] == key){
//            printf("index = %i\n", i);
//            break;
//        }
//    }
    /*
    1.每次都取出mid对应的值和要查找的值比较
    2.如果取出的值小于我们要找的值, 就让min变为mid+1, 然后再重新计算Mid值
    3.如果取出的值大于我们要找的值, 就让max变为mid-1, 然后再重新计算mid值
    4.如果min都大于Max还没有找到, 那么就不用找了
     */
    int min = 0;
    int len = sizeof(nums) / sizeof(nums[0]);
    int max = len - 1;
    int mid = (min + max) / 2;
    while(min <= max){
        if(nums[mid] > key){
            max = mid - 1;
            mid = (min + max) / 2;
        }else if(nums[mid] < key){
            min = mid + 1;
            mid = (min + max) / 2;
        }else{
            printf("index = %i\n", mid);
            break;
        }
    }
    printf("没有找到\n");
    return 0;
}
