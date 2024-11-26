#include <stdio.h>

int main()
{
    /*
     * break注意点:
     * 1.break语句只能用于switch语句和循环语句, 离开这两个语句没有任何的意义
     * 2.break语句的后面不能编写代码, 因为执行不到
     *
     * break在switch中的作用:
     * 立即结束switch语句
     *
     * break在循环语句中的作用:
     * 立即结束当前的循环语句
     */

    /*
    switch(2){
    case 1:
        printf("这是1\n");
        break;
    case 2:
        printf("这是2\n");
        break;
        printf("123\n");
    default:
        printf("other\n");
    }
    */

    for(int i = 0; i < 10; i++){
        printf("i = %i\n", i);
        break;
        printf("123\n");
    }

    if(1){
        break; // 报错, 离开switch和循环没有意义, 不能使用
    }
    return 0;
}
