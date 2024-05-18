
#include <stdio.h>

//使用宏代替一长串的数字
#define PI   3.1415926

//使用宏代替字符串
#define  SAY   "欢迎来到我们的课程！\n"
#define  SAY   "Hello!\n" 

//使用宏代替一大串的代码， \表示还有下一行
#define  CODE   for(int i=0;i<10;++i) \
{ \
printf("第%d次打印！\n",i);\
}


//带参数的宏，有点像函数
#define MAX(a,b)   a>b?a:b


//宏陷阱，需要注意 ,加上括号，以防参数是表达式
#define  Mul(x,y)     (x)*(y)



int main()  
{
    float s = PI * 10 * 10;
    printf("圆的面积是%f\n", s);

    printf(SAY);
     
    CODE
         
     int  m = MAX(111,222); //相当于直接写   int  c= 111>222?111:222;
    printf("较大的是%d\n", m);

      int a = 1;
      int b = 3;
      int  c = Mul(a + b, 10); //为什么不是40
                                           //    a+b *10 ,结果是31
     printf("结果是 %d\n", c); 

}
