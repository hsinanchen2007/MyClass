#include <stdio.h>

int main()
{
    // 1.case�Ĵ�͸����, һ�������case��default�����break����ʡ��
    // ��Ϊһ����һ��case����default��ƥ����, ��ô������case��default����ʧЧ
    // 2.break��switch����е�����: ����������ǰ��switch���
//    int day = 1;
//    switch(day){
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

    // 3.default��λ�ÿ������д, Ҳ���ǲ���д�����
    // ��������д��ʲô�ط�, default����������case��ƥ��֮��Ż�ִ��
//    int day = 1;
//    switch(day){
//    default:
//        printf("OTHER\n");
//        break;
//    case 1:
//        printf("����һ\n");
//        break;
//    case 2:
//        printf("���ڶ�\n");
//        break;
//    }

    // 4.���defaultд�����, ��ôdefault�����break����ʡ��
    // ���default����д�����, ��ôdefault�����break����ʡ��
    int day = 3;
    switch(day){
    default:
        printf("OTHER\n");
//        break;
    case 1:
        printf("����һ\n");
        break;
    case 2:
        printf("���ڶ�\n");
        break;
//    default:
//        printf("OTHER\n");
////        break;
    }

    // �ܽ�: һ������¶���Ҫʡ��break, һ������¶���defaultд�����
    return 0;
}
