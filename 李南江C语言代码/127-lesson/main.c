#include <stdio.h>
#include <string.h>
void myStrcat(char str1[], char str2[]);
int main()
{
    // 2.用于拼接字符串的函数
    char str1[] = {'l','n','j','\0'};
    char str2[] = {'i','t','\0'};
    printf("str1 = %s\n", str1);
    // 会将第二个参数拼接到第一个参数后面
    // 注意点: 必须保证第一个参数的容量足够, 否则会拼接失败
//    strcat(str1, str2);
    myStrcat(str1, str2);
    printf("str1 = %s\n", str1);
    return 0;
}

void myStrcat(char str1[], char str2[]){
    // 1.找到第一个参数\0的位置
    int index = 0;
    while(str1[index] != '\0'){
        index++;
    }
    // 2.依次取出第二个参数的每一个元素
    // 3.从第一个参数\0的位置依次存储
    int i = 0;
    while(str2[i] != '\0'){
        str1[index] = str2[i];
        index++;
        i++;
    }
    str1[index] = '\0';
}
