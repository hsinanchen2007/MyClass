
#include <stdio.h>

//全局变量-定义在函数外部的，程序结束后就销毁了
char weixin[] = "卫星";

//局部变量-定义在函数内部的，出了}之后就销毁了
void  home( int  a )//参数a也是局部变量
{
    char wc[5] = "浴室";//局部变量 
    printf("在家里{}可以访问局部变量 %s\n", wc);

    printf("在家里访问全局变量 %s\n", weixin);

}//wc ，a 在这里销毁 


int main()
{
    home(100);

   //printf("在home外无法访问局部变量wc  %s\n", wc);

     
    int  c=200;//这里也是一个局部变量，因为a在main函数里面
    printf("在main访问局部变量c  %d\n", c);

    printf("在main访问全局变量 %s\n", weixin);

   //printf("在main访问全局变量 %s\n", weixin2);

}//a在这里销毁


//这个全局变量的范围从这里往下才认识，上面的访问不到
char  weixin2[] = "卫星2";
