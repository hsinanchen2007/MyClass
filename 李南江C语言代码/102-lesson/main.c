#include <stdio.h>

int main()
{
    /*
     * 1.�������͵�����
     * ���߲���ϵͳ��Ҫ������Ĵ洢�ռ�
     * char  1���ֽڴ洢�ռ�    -2(7)~2(7)-1
     * int   4���ֽڴ洢�ռ�    -2(31)~2(31)-1
     *
     * 2.����˵����?
     * ��C����������������˵����, һ��������˵�����ȵ�, һ��������˵������λ��
     *
     * 3.˵�����ȵ�����˵����
     * �Ա����Ĵ洢�ռ�������ݻ�������, ˵�����ȵ�����˵�������������Ż��洢�ռ�
     * short  2���ֽڴ洢�ռ�   -2(15)~2(15)-1
     * long   ��32λ��������ռ��4���ֽ�, ��64λ��������ռ8���ֽ�
     * long long 8���ֽڴ洢�ռ�  -2(63)~2(63)-1
     *
     *
     * 4.������������˵����˵��������
     * short  --> %hi  %hd
     * long   --> %li  %ld
     * long long --> %lli   %lld
     *
     * 5.ע���:
     * ����˵�����ȵ�����˵����һ�㶼������˵��int����, ������ʹ�õ�ʱ��int����ʡ��
     *
     * short int  == short
     * long int  == long
     * long long int == long long
     *
     *
     * 6.˵������λ������˵����
     * ������ȷ�ĸ��߲���ϵͳ���Ա�����Щ����(����/����/��)
     * signed     ���߲���ϵͳ���Դ洢����/����/��
     * unsigned   ���߲���ϵͳ���Դ洢����/��, ���ǲ��ܴ洢����
     *
     * 7.ע���:
     * Ĭ�������һ����������signed, ����һ�������signed���ǲ���д
     * ���һ��������unsigned������, ��ô�ڻ�ȡ��ʱ�����Ҫʹ��%u����ȡ
     */
//    char ch = 127;
//    char ch = 300;
//    printf("ch = %i\n", ch);

    /*
    int num1 = 123;  // 4���ֽ�
    int size1 = sizeof(num1);
    printf("size1 = %i\n", size1);

    short int num2 = 123; // 2���ֽ�
    int size2 = sizeof(num2);
    printf("size2 = %i\n", size2);

    long int num3 = 123; // 4���ֽ�
    int size3 = sizeof(num3);
    printf("size3 = %i\n", size3);

    long long int num4 = 123; // 8���ֽ�
    int size4 = sizeof(num4);
    printf("size4 = %i\n", size4);
    */

    /*
//    int num = 12345678901;
    long long int num = 12345678901;
    // ע���: C���Բ�����ô��, ֻ����ôȡ
    // %i/%d���ǰ���int������ȡ
//    printf("num = %i\n", num);
    printf("num = %lli\n", num);
    */

    /*
    short num1 = 123;
    int size1 = sizeof(num1);
    printf("size1 = %i\n", size1);

    long num3 = 123; // 4���ֽ�
    int size3 = sizeof(num3);
    printf("size3 = %i\n", size3);

    long long num4 = 123; // 8���ֽ�
    int size4 = sizeof(num4);
    printf("size4 = %i\n", size4);
    */

//    int num = 123;
//    printf("num = %i\n", num);
//    num = 0;
//    printf("num = %i\n", num);
//    num = -123;
//    printf("num = %i\n", num);

//    signed int num = 123;
//    printf("num = %i\n", num);
//    num = 0;
//    printf("num = %i\n", num);
//    num = -123;
//    printf("num = %i\n", num);

    unsigned int num = 123;
    printf("num = %u\n", num);
    num = 0;
    printf("num = %u\n", num);
    num = -123;
    printf("num = %u\n", num);
    return 0;
}
