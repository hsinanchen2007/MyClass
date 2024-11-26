#include <stdio.h>
#include <string.h>
void myStrcpy(char str1[], char str2[]);
int main()
{
    // 3.用于字符串拷贝的函数
    char str1[] = {'l','n','j','\0'};
    char str2[] = {'i','t','\0'};
    printf("str1 = %s\n", str1);
    // 会将第二个参数的内容, 拷贝到第一个参数中
    // 注意点: 必须保证第一个参数的容量足够, 否则会出现数据混乱的问题
//    strcpy(str1, str2);
    myStrcpy(str1, str2);
    printf("str1 = %s\n", str1);

    return 0;
}

void myStrcpy(char str1[], char str2[]){
    // 1.遍历取出第二个参数的每一个元素
    int index = 0;
    while(str2[index] != '\0'){
        // 2.将取出的元素放到第一个参数中
        str1[index] = str2[index];
        index++;
    }
    str1[index] = '\0';
}
