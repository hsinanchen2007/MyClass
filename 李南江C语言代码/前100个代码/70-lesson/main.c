#include <stdio.h>

int main()
{
    // 需求: 要求往屏幕上输出 ****
    // 需求: 要求往屏幕上输出三行 ****
//    printf("****\n");

//    printf("*");
//    printf("*");
//    printf("*");
//    printf("*");
//    printf("\n");

    /*
    for(int i = 0; i < 4; i++){
        printf("*");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        printf("*");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        printf("*");
    }
    printf("\n");
    */

    // 规律:
    // 在循环嵌套中, 外循环控制行数, 内循环控制列数
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 4; i++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
