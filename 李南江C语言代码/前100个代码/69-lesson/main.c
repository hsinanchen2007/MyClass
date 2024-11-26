#include <stdio.h>

int main()
{
    /*
     * 循环嵌套
     * 在C语言中循环结构是可以嵌套使用的
     * 循环嵌套的规律:
     * 内循环执行的次数是: 外循环执行次数 * 内循环执行次数
     *
     * 在循环嵌套中break结束的是自己所在的循环
     * 在循环嵌套中continue跳过的是自己所在的循环
     */

    /*
    for(int i = 0; i < 2; i++){
//        printf("外循环被执行了\n");
        for(int j = 0; j < 3; j++){
            printf("内循环被执行了\n");
        }
    }
    */
    /*
    for(int i = 0; i < 2; i++){
        printf("--------外循环被执行了\n");
        for(int j = 0; j < 3; j++){
            printf("内循环被执行了\n");
            break;
        }
    }
    */
    for(int i = 0; i < 2; i++){
        printf("--------外循环被执行了\n");
        for(int j = 0; j < 3; j++){
            if(j == 1){
                continue;
            }
            printf("内循环被执行了\n"); // 1 2
        }
    }

    return 0;
}
