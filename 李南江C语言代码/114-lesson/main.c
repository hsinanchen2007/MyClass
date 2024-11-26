#include <stdio.h>
void printArray(int nums[4], int len);
int main()
{
    int nums[4] = {4, 3, 5, 1}; // {1, 3, 4, 5}
    int len = sizeof(nums) / sizeof(nums[0]);
    printArray(nums, len);
    for(int i = 0; i < 3 ;i++){
        for(int j = i; j < 3; j++){
//            printf("*");
//            printf("i = %i, j = %i\n", i, j + 1);
            if(nums[i] > nums[j + 1]){
                int temp = nums[i];
                nums[i] = nums[j +1];
                nums[j + 1] = temp;
            }
        }
//        printf("\n");
    }
    printf("-------------------\n");
    printArray(nums, len);
    return 0;
}
void printArray(int nums[4], int len){
    for(int i = 0; i < len; i++){
        printf("nums[%i] = %i\n", i, nums[i]);
    }
}
