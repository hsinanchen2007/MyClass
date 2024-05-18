
#include <stdio.h>

void fun()
{
    printf("这是一个递归函数！\n");

    fun();//调用自己
}


int  WhatIsNum(int N)
{
    if (N == 1)
    {
        return 100;//第一个童鞋知道他自己是100号
    }
    else
    { //前面的童鞋都不知道自己是几号
        return  WhatIsNum(N - 1) + 1;//问下一个童鞋的号码，加上1就是自己的号
    }
   
}


int main()
{
   // fun();

    //调用函数
    int num = WhatIsNum(4);
    printf("我的号码是%d\n", num);
}