#include <stdio.h>

int main()
{
    // 获取1～100之间 7的倍数的个数
    // 1.拿到1~100之间所有的数
    int num = 1;
    int count = 0;
    while(num <= 100){
        // 2.利用当前拿到的数%7, 如果等于0, 那么就是7的倍数
        if(num % 7 == 0){
            printf("num = %i\n", num); // 1 2 3
            count++;
        }
        num++; // 2 3 4
    }
    printf("count = %i\n", count);
    return 0;
}
