#include <stdio.h>

int main()
{
    /*
     * while��ʽ:
     * while(�������ʽ){
     *      �ظ�ִ�еĴ���;
     * }
     * �ص�: ֻ���������ʽΪ��, �Ż�ִ��{}�еĴ���
     *
     * dowhile��ʽ:
     * do{
     *      �ظ�ִ�еĴ���;
     * }while(�������ʽ);
     * �ص�: �����������ʽ�Ƿ�Ϊ��, ����ִ��һ��{}�еĴ���
     */

//    while(0){
//        printf("�ظ�ִ�еĴ���\n");
//    }

//    do{
//        printf("�ظ�ִ�еĴ���\n");
//    }while(0);

//    int num = 1;
//    while(num <= 10){
//        printf("�����ӵ�%i\n", num);
//        num++;
//    }

    int num = 1;
    do{
        printf("�����ӵ�%i\n", num);
        num++;
    }while(num <= 10);
    return 0;
}
