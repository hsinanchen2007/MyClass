#include <stdio.h>

void change(int value){ // �����value�����β�
    value = 666;
}
int main()
{
    /*
     * �ں������޸��β�, ����Ӱ�쵽����ʵ��?
     * �β�: �����ں���()�ж���ı���
     * ʵ��: ���ǵ��ú�����ʱ�򴫵ݵĲ���
     *
     * ע���:
     * ��������ֻ�к������β��ǻ����������͵�ʱ��Ż����
     * int char float double
     */
    int num = 123;
    printf("num = %i\n", num); // 123
    change(num); // �����num����ʵ��
    printf("num = %i\n", num); // 666? 123?
    return 0;
}
