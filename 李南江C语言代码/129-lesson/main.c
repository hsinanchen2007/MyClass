#include <stdio.h>
#include <string.h>
int myStrcmp(char str1[], char str2[]);
int main()
{
    // 4.�����ַ����Ƚϵĺ���
    char str1[] = {'a','b','c','\0'};
    char str2[] = {'a','b','d','\0'};
    // �����������������бȽ�
    // �����һ���������ڵڶ�������, �ͻ᷵��1
    // �����һ������С�ڵڶ�������, �ͻ᷵��-1
    // �����һ���������ڵڶ�������, �ͻ᷵��0
//    int res = strcmp(str1, str2);
    int res = myStrcmp(str1, str2);
    printf("res = %i\n", res);
    return 0;
}

int myStrcmp(char str1[], char str2[]){
    int index = 0;
    while(str1[index] != '\0' || str2[index] != '\0'){
        if(str1[index] > str2[index]){
            return 1;
        }else if(str1[index] < str2[index]){
            return -1;
        }
        index++;
    }
    return 0;
}
