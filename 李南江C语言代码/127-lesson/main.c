#include <stdio.h>
#include <string.h>
void myStrcat(char str1[], char str2[]);
int main()
{
    // 2.����ƴ���ַ����ĺ���
    char str1[] = {'l','n','j','\0'};
    char str2[] = {'i','t','\0'};
    printf("str1 = %s\n", str1);
    // �Ὣ�ڶ�������ƴ�ӵ���һ����������
    // ע���: ���뱣֤��һ�������������㹻, �����ƴ��ʧ��
//    strcat(str1, str2);
    myStrcat(str1, str2);
    printf("str1 = %s\n", str1);
    return 0;
}

void myStrcat(char str1[], char str2[]){
    // 1.�ҵ���һ������\0��λ��
    int index = 0;
    while(str1[index] != '\0'){
        index++;
    }
    // 2.����ȡ���ڶ���������ÿһ��Ԫ��
    // 3.�ӵ�һ������\0��λ�����δ洢
    int i = 0;
    while(str2[i] != '\0'){
        str1[index] = str2[i];
        index++;
        i++;
    }
    str1[index] = '\0';
}
