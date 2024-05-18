
#include <stdio.h>

int main()
{
    //定义一个常量，一旦定义，值永远不能改变
    const int a = 100;
    
    printf("常量a的值是%d\n", a);

    //企图修改常量的内容
    //a = 200;//不能修改常量的值，会报错


    //const int b; //不赋初始值，没有意义
   

}
