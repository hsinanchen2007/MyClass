#include <stdio.h>

int main()
{
    /*
     需求:
     *
     **
     ***
     ****

     ****
     ****
     ****
     ****

     规律:
     在企业开发中, 尖尖朝上, 需要修改内循环的条件表达式等于外循环的变量
     */

//    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
//        count++;
        printf("\n");
    }
    return 0;
}
