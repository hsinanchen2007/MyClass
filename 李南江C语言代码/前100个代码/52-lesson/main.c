#include <stdio.h>

int main()
{
    // 1.switch�е�case�����ֵ�����ظ�
//    int day = 1;
//    switch(day){
//    case 1:
//        printf("����һ\n");
//        break;
//    case 1:
//        printf("���ڶ�\n");
//        break;
//    default:
//        printf("OTHER\n");
//        break;
//    }

    // 2.switch�е�case���治�ܶ����µı���
    //  �����Ҫ�����µı���, �������{}
//    int day = 1;
//    switch(day){
//    case 1:
////        int num = 666; // ����
//        printf("����һ\n");
//        break;
//    case 2:{
//        int num = 666;
//        printf("���ڶ�\n");
//        break;
//        }
//    default:
//        printf("OTHER\n");
//        break;
//    }

    // 3.switch�����()�п��Էű���/����/���ʽ, ���ǲ��ܷ�С��
//    int day = 1;
////    switch(day){ // ����
////    switch(3){ // ����
////    switch(1 + 1){ // ���ʽ
////    switch(3.14){ // С��
//    switch(3.14 + 1){ // С��
//    case 1:
//        printf("����һ\n");
//        break;
//    case 2:
//        printf("���ڶ�\n");
//        break;
//    default:
//        printf("OTHER\n");
//        break;
//    }

    // 4.switch�е�case����ֻ�ܷų����ͳ������ʽ, ���ܷű�����С��
    int day = 1;
    int num = 3;
    switch(day){
    case 1: // ����
        printf("����һ\n");
        break;
    case 1 + 1: // �������ʽ
        printf("���ڶ�\n");
        break;
//    case num: // ����
//        printf("������\n");
//        break;
//    case 3.14: // С��
//        printf("������\n");
//        break;
    case 1 + 3.14: // С��
        printf("������\n");
        break;
    default:
        printf("OTHER\n");
        break;
    }

    return 0;
}
