#include <stdio.h>

int main()
{
    // �ֲ�������������
    // 1.��ͬ�������п��Գ���ͬ���ľֲ�����
    // 2.�ڷ��ʱ�����ʱ����þͽ�ԭ��, �Լ������Լ���, �Լ�û���ٿ���������û��
    /*
    int num = 666;
    {
        int num = 777;
        printf("{}num = %i\n", num); // 777
    }
    printf("num = %i\n", num); // 666
    */

    // ע���: forѭ����{}�п��Զ����()��ͬ���ı���
    //        ��Ϊ()��{}��������ͬ
//    for(int num = 1; num <= 10; num++){
//        int num = 666;
//        printf("num = %i\n", num); // ?
//    }

    // ע���: forѭ����{}�ж���ı���, ������forѭ����()�з���
    for(int num = 1; num <= 10; count++){
        int count = 666;
        printf("num = %i\n", num); // ?
    }
    return 0;
}
