
#include <stdio.h>

int main()
{
    /*
     * 1.�ַ�����ָ��
     * 1.1�ַ����ı��ʾ���һ�����������
     * ����Ķ����ַ�, ������\0��β
     * 1.2����������ľ�������ĵ�ַ
     * ���Խ���������ֵ��һ��ָ�����
     * 1.3��ʽ��Ϊ���,���Զ����ַ����ֶ���һ�ַ�ʽ
     * char str[] = {'',''};
     * char str[] = "";
     * char *str = "";
     *
     * 2.���������ָ�붨���ַ���������
     * �������鶨���ַ���������ջ��
     * ����ָ�붨���ַ��������ڳ�������
     *
     * 3.ע���:
     * �����������鶨����ַ���������ջ��, ���Բ���ϵͳ��Ҫ��ǰ֪�����ٶ��洢�ռ�
     * �����������鶨���ַ�������ֱ������ָ���������
     */
    /*
    char str1[] = {'l', 'n', 'j', '\0'};
    char str2[] = "lnj";
    char *str3 = "lnj";
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);
    */

    char str1[] = {'l', 'n', 'j', '\0'};
    char str2[] = {'l', 'n', 'j', '\0'};
    char str3[] = "lnj";
    char str4[] = "lnj";
    printf("str1 = %p\n", str1);
    printf("str2 = %p\n", str2);
    printf("str3 = %p\n", str3);
    printf("str4 = %p\n", str4);

    char *str5 = "abc";
    char *str6 = "abc";
    printf("str5 = %p\n", str5);
    printf("str6 = %p\n", str6);
    return 0;
}
