#include <stdio.h>
#include <string.h>
int myStrlen(char str1[]);
int main()
{
    // 1.���ڼ����ַ����ĳ���
    char str1[] = {'l','n','j','\0'};
//    int len = strlen(str1);
    int len = myStrlen(str1);
    printf("len = %i\n", len);

    return 0;
}
int myStrlen(char str1[]){
    // 1.������������ַ����ĳ���
    int len = 0;
    // 2.����ȡ���ַ����е�ÿһ��Ԫ��
    // 3.�жϵ�ǰȡ����Ԫ���Ƿ���\0, ������Ǿ��ó���+1
    while(str1[len] != '\0'){
        len++;
    }
    // 4.���ؼ���Ľ��
    return len;
}
