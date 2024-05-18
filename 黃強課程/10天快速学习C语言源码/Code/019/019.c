
#include <stdio.h>


//定义一个函数，用来放重复被使用的代码
//无参数，无返回值
void  DaXiangFangBinXiang()
{
    printf("第1步，把冰箱门打开！\n");
    printf("第2步，把大象装进去！\n");
    printf("第3步，把冰箱门关上！\n");
}
 

//定义一个有参数，有返回值的函数
int Sum(int a, int b)
{
    return a + b; //使用return语句返回结果
}

int main()
{
    //调用函数
    DaXiangFangBinXiang();

    printf("\n\n");

   //想把第2头大象放冰箱
    DaXiangFangBinXiang();

    printf("\n\n");

    //求111+222的和
    int s1 = Sum(111, 222);//调用函数，并且把返回值赋给s1
    printf("111+222 = %d\n", s1);
   
    //求34+55的和
    int s2 = Sum(34, 55);//调用函数，并且把返回值赋给s2
    printf("34+55 = %d\n", s2);

}
