#include <stdio.h>
#include <string.h>
int myStrlen(char str1[]);
int main()
{
    // 1.用于计算字符串的长度
    char str1[] = {'l','n','j','\0'};
//    int len = strlen(str1);
    int len = myStrlen(str1);
    printf("len = %i\n", len);

    return 0;
}
int myStrlen(char str1[]){
    // 1.定义变量保存字符串的长度
    int len = 0;
    // 2.依次取出字符串中的每一个元素
    // 3.判断当前取出的元素是否是\0, 如果不是就让长度+1
    while(str1[len] != '\0'){
        len++;
    }
    // 4.返回计算的结果
    return len;
}
