#include <stdio.h>
char *test();
void change(int *p);
int main()
{
    // 1.通过{}定义的字符串, 不能直接赋值给指针变量
    //  只有通过""定义的字符串, 才能直接赋值给指针变量
//    char *str = {'l', 'n', 'j', '\0'};
//    char *str = "lnj";
//    printf("str = %s\n", str);

    // 2.如果在一个函数中通过数组保存了一个字符串, 那么这个字符串不能作为函数的返回值, 因为外界获取不到
    //   如果在一个函数中通过指针保存了一个字符串, 那么这个字符串可以作为函数的返回值, 因为外界可以获取
    //   通过数组保存的字符串存储在栈中
    //   通过指针变量保存的字符串存储在常量区中
    //   存储在栈中的数据有一个特点: 离开作用域就会自动释放
    //   存储在常量区中的数据有一个特点: 只有程序结束才会释放
//    char *res = test();
//    printf("res = %s\n", res);

    // 3.如果数组作为函数的参数, 那么函数的形参最好写指针而不要写数组
    int ages[] = {1, 3, 5};
    printf("ages[1] = %i\n", ages[1]);
    change(ages);
    printf("ages[1] = %i\n", ages[1]);
    return 0;
}
//void change(int values[]){
void change(int *p){
    p[1] = 666;
}

char *test(){
//     char str[] = {'l', 'n', 'j', '\0'};
    char *str = "lnj";
     printf("str = %s\n", str);
     return str;
}
