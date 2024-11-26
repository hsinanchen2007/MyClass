#include <stdio.h>
int moveToLeft()
{
    // 向左变道
    printf("打左转向灯\n");
    printf("看左边后视镜\n");
    printf("看车内后视镜\n");
    printf("方向向左调整\n");
    printf("向左变道完成\n");
}
int moveToRight()
{
    // 向右变道
    printf("打右转向灯\n");
    printf("看右边后视镜\n");
    printf("方向向右调整\n");
    printf("向右变道完成\n");
}

int main()
{
    /*
     * 1.什么是函数?
     * 函数是专门用于封装代码的
     *
     * 2.不使用函数的弊端
     * 2.1冗余代码太多
     * 2.2需求发生变更, 需要修改很多代码
     *
     * 3.使用函数的好处
     * 3.1减少了冗余代码
     * 3.2需求发生变更, 修改的代码变少了
     */

    /*
    // 向左变道
    printf("打左转向灯\n");
    printf("看左边后视镜\n");
//    printf("看车内后视镜\n");
    printf("方向向左调整\n");
    printf("向左变道完成\n");

    // 向右变道
    printf("打右转向灯\n");
    printf("看右边后视镜\n");
    printf("方向向右调整\n");
    printf("向右变道完成\n");

    // 向左变道
    printf("打左转向灯\n");
    printf("看左边后视镜\n");
//    printf("看车内后视镜\n");
    printf("方向向左调整\n");
    printf("向左变道完成\n");
    */

    // 向左变道
    moveToLeft();
    // 向右变道
    moveToRight();
    // 向左变道
    moveToLeft();
    return 0;
}
