
#include <stdio.h>

int main()
{
    //赋值运算符 =  ，把右边的值给左边
    int  a = 50; 
    printf("a的值是%d\n", a);

    a += 100;//等价于 a= a+100;
    printf("a+=100后a的值是%d\n", a);

    a -= 100;//等价于 a = a-100;
    printf("a-=100后a的值是%d\n", a);

    a *= 100;//等价于 a = a*100;
    printf("a*=100后a的值是%d\n", a);

    a /= 100;//等价于 a = a/100;
    printf("a/=100后a的值是%d\n", a);


    //验证一道课堂练习题
    int c = 2;  
    c -= (c + 2); //等价于  c = c-(c+2);
    printf("c的值是%d\n", c);

}
