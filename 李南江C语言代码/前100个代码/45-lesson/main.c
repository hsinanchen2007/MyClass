#include <stdio.h>

int main()
{
    // �����û������1��7�������������û�����������������Ӧ�����ڼ�
    // 1.��ʾ�û�����һ��1~7������
    printf("������һ��1~7������, �Իس�����\n");
    // 2.����һ�����������û����������
    int day;
    // 3.�����û����������
    scanf("%i", &day);
    // 4.�ж��û����������, �����жϽ��������ڼ�
//    if(1 == day){
//        printf("����һ\n");
//    }else if(2 == day){
//        printf("���ڶ�\n");
//    }else if(3 == day){
//        printf("������\n");
//    }else if(4 == day){
//        printf("������\n");
//    }else if(5 == day){
//        printf("������\n");
//    }else if(6 == day){
//        printf("������\n");
//    }else if(7 == day){
//        printf("������\n");
//    }else{
//        printf("û���������\n");
//    }

    if(day > 7 || day < 1){
        printf("û���������\n");
    }else if(1 == day){
        printf("����һ\n");
    }else if(2 == day){
        printf("���ڶ�\n");
    }else if(3 == day){
        printf("������\n");
    }else if(4 == day){
        printf("������\n");
    }else if(5 == day){
        printf("������\n");
    }else if(6 == day){
        printf("������\n");
    }else{
        printf("������\n");
    }
    return 0;
}
