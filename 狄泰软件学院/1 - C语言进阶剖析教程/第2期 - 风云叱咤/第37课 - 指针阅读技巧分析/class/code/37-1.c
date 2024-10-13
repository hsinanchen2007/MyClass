#include <stdio.h>

/*
    指针阅读技巧解析
    左右法则
    从最里层的圆括号中未定义的标示符看起
    首先往右看，再往左看
    遇到圆括号或方括号时可以确定部分类型，并调整方向
    重复2，3步骤，直到阅读结束
*/

int main()
{ 
    int (*p1)(int*, int (*f)(int*));
    
    int (*p2[5])(int*);
    
    int (*(*p3)[5])(int*);

    int*(*(*p4)(int*))(int*);
    
    int (*(*p5)(int*))[5];

    return 0;
}

