#include <stdio.h>

int main()
{
    /*
     * continue注意点:
     * 1.只能用于循环结构, 离开循环结构没有任何意义
     * 2.continue的后面也不能编写任何的语句, 因为执行不到
     *
     * continue在循环中的作用:
     * 跳过本次循环, 进入下一次的循环
     * 在循环结构中, 如果执行到了continue语句, 会立即回到循环的条件表达式开始重新执行
     */

    for(int i = 0; i < 10; i++){
        if(i == 1){
            continue;
//            printf("123");
        }
        printf("i = %i\n", i); // 0 2
    }
    return 0;
}
