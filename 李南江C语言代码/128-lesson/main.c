#include <stdio.h>
#include <string.h>
void myStrcpy(char str1[], char str2[]);
int main()
{
    // 3.�����ַ��������ĺ���
    char str1[] = {'l','n','j','\0'};
    char str2[] = {'i','t','\0'};
    printf("str1 = %s\n", str1);
    // �Ὣ�ڶ�������������, ��������һ��������
    // ע���: ���뱣֤��һ�������������㹻, �����������ݻ��ҵ�����
//    strcpy(str1, str2);
    myStrcpy(str1, str2);
    printf("str1 = %s\n", str1);

    return 0;
}

void myStrcpy(char str1[], char str2[]){
    // 1.����ȡ���ڶ���������ÿһ��Ԫ��
    int index = 0;
    while(str2[index] != '\0'){
        // 2.��ȡ����Ԫ�طŵ���һ��������
        str1[index] = str2[index];
        index++;
    }
    str1[index] = '\0';
}
