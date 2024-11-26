#include <stdio.h>

int main()
{
    // 需求: 要求将小写字母转换为大写字母
    // 1.定义一个变量保存一个小写字母
    char ch = 't';
    // 2.将小写字母转换为大写字母
//    char res = ch - 32;
    char res = ch - ('a' - 'A');
    // 3.输出转换之后的结果
    printf("res = %c\n", res);

    // 作业:
    // 要求封装两个函数, 一个用于实现将小写转换为大写, 另一个用于实现将大写转换为小写
    return 0;
}
