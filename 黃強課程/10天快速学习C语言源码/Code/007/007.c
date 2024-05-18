
#include <stdio.h>

int main()
{
     //使用printf在控制台中打印一些信息

    printf("你好！\n");//不带格式符,\n代表换行

    char c = 'A'; //字符格式符 %c
    printf("打印字符类型   %c , %c\n", c , 'B');

    int  d = 100;//整数格式符 %d
    printf("打印整数类型   %d , %d\n", d,  200 );

    float  f = 0.123;
    double g = 0.456;
    printf("打印浮点数类型   %f , %f ,%f\n", f ,g ,0.789);

}
