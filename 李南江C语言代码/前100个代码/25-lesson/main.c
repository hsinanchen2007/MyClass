#include <stdio.h>

int main()
{
    /*
     * 自增自减运算符写在变量前面和后面的区别
     * 1.如果自增自减运算符写在变量的后面, 那么会先参与其它运算, 然后再自增自减
     * 2.如果自增自减运算符写在变量的前面, 那么会先自增自减然后再参与其它的运算
     */

    int num = 5;
    // 自增写在变量的后面
    // 那么会先参与其它运算, 然后再自增
    // 相当于: int value = 5 + num; num++;
//    int value = 5 + num++;
//    printf("value = %i\n", value); // 10
//    printf("num = %i\n", num); // 6

    // 自增写在变量的前面
    // 那么会先自增然后再参与其它的运算
    // ++num; int value = 5 + num;
//    int value = 5 + ++num;
//    printf("value = %i\n", value); // 11
//    printf("num = %i\n", num); // 6

    // 自减在变量的后面
    // 那么会先参与其它运算, 然后再自减
    // int value = 5 + num; num--;
//    int value = 5 + num--;
//    printf("value = %i\n", value); // 10
//    printf("num = %i\n", num); // 4

    // 自减在变量的前面
    //  那么会先自减然后再参与其它的运算
    //   num--; int value = 5 + num;
    int value = 5 + --num;
    printf("value = %i\n", value); // 9
    printf("num = %i\n", num); // 4
    return 0;
}
