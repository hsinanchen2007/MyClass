#include <stdio.h>

int main()
{
    /*
     * �����û������һ������month�����·ݣ������·������Ӧ�ļ���
     * 3/4/5 ���� 6/7/8 �ļ� 9/10/11 �＾ 12/1/2 ����
     */
    // 1.��ʾ�û�����һ��1~12������
    printf("������һ��1~12������, �Իس�����\n");
    // 2.������������û����������
    int month;
    // 3.�����û����������
    scanf("%i", &month);
    // 4.�ж���ʲô����, Ȼ��������
//    if(month == 3 || month == 4 || month == 5){
//        printf("����\n");
//    }else if(month == 6 || month == 7 || month == 8){
//        printf("�ļ�\n");
//    }else if(month == 9 || month == 10 || month == 11){
//        printf("�＾\n");
//    }else if(month == 12 || month == 1 || month == 2){
//        printf("����\n");
//    }else{
//        printf("û���������\n");
//    }

//    if(month < 1 || month > 12){
//        printf("û���������\n");
//    }else if(month == 3 || month == 4 || month == 5){
//        printf("����\n");
//    }else if(month == 6 || month == 7 || month == 8){
//        printf("�ļ�\n");
//    }else if(month == 9 || month == 10 || month == 11){
//        printf("�＾\n");
//    }else if(month == 12 || month == 1 || month == 2){
//        printf("����\n");
//    }

    if(month < 1 || month > 12){
        printf("û���������\n");
    }else if(month >= 3 && month <= 5){
        printf("����\n");
    }else if(month >= 6 && month <= 8){
        printf("�ļ�\n");
    }else if(month >= 9 && month <= 11){
        printf("�＾\n");
    }else{
        printf("����\n");
    }
    return 0;
}
