 
#include <stdio.h>

//定义枚举类型
enum Color
{
    Red, //值是0，后面递增
    Blue,//1
    Green,//2
    Yellow //3
};

int main()
{
    enum Color c = Red;

    printf(" Red 的值是 %d \n", c);
    printf(" Blue 的值是 %d \n", Blue);
    printf(" Green 的值是 %d \n", Green);
    printf(" Yellow 的值是 %d \n", Yellow);

}
 