#include <stdio.h>
// 定义在大括号外: 全局作用域
enum Gender{
    male,
    femal
};
void test();
int main()
{
    /*
     * 1.枚举类型作用域
     * 和结构体一样分为局部作用域和全局作用域
     *
     * 2.枚举变量的多种定义格式
     * 和结构体一样分为:
     * 2.1先定义枚举类型, 再定义枚举变量
     * 2.2定义枚举类型的同时定义枚举变量
     * 2.3定义枚举类型的同时定义枚举变量, 并且省略枚举类型名称
     */
    /*
    {
        // 定义在大括号: 局部作用域
        enum Gender{
            male,
            femal
        };
        enum Gender g1 = male;
    }
    enum Gender g2 = male; // 报错
    */

    enum Gender g1 = male;


    // 1.先定义枚举类型, 再定义枚举变量
    /*
    enum Gender{
        male,
        femal
    };
    enum Gender g;
    */

    // 2.定义枚举类型的同时定义枚举变量
    /*
    enum Gender{
        male,
        femal
    } g;
    */

    // 3.定义枚举类型的同时定义枚举变量, 并且省略枚举类型名称
    /*
    enum{
        male,
        femal
    } g;
    */
}
void test(){
    enum Gender g2 = male;
}
