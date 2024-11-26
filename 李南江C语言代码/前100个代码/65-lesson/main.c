#include <stdio.h>

int main()
{
    // 局部变量的作用域
    // 1.不同作用域中可以出现同名的局部变量
    // 2.在访问变量的时候采用就近原则, 自己有用自己的, 自己没有再看看祖先有没有
    /*
    int num = 666;
    {
        int num = 777;
        printf("{}num = %i\n", num); // 777
    }
    printf("num = %i\n", num); // 666
    */

    // 注意点: for循环的{}中可以定义和()中同名的变量
    //        因为()和{}的作用域不同
//    for(int num = 1; num <= 10; num++){
//        int num = 666;
//        printf("num = %i\n", num); // ?
//    }

    // 注意点: for循环的{}中定义的变量, 不能在for循环的()中访问
    for(int num = 1; num <= 10; count++){
        int count = 666;
        printf("num = %i\n", num); // ?
    }
    return 0;
}
