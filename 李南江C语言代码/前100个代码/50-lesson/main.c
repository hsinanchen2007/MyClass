#include <stdio.h>

int main()
{
    /*
     * switchѡ��ṹ
     *
     * ��ʽ:
     * switch(���ʽ){
     *    case �������ʽ:
     *         ���������ʽ���Ƶ����;
     *         break;
     *    case �������ʽ:
     *         ���������ʽ���Ƶ����;
     *         break;
     *    default:
     *         ��default���Ƶ����;
     *         break;
     * }
     *
     * �ص�:
     * 1.�ڶ�case��defaultֻ��һ���ᱻִ��, ����ֻ�ᱻִ��һ��
     * 2.��������������ж�ÿһ�����ʽ��ֵ�Ƿ��switch���ʽ��ֵ���, ������, ��ִ�к���Ĵ���
     * ��������, �ͼ����ж�������case, �������case�������, ��ô��ִ��default����Ĵ���
     */

    int day = 3;
    switch(day){
    case 1: // day == 1
        printf("����һ\n");
        break;
    case 2: // day == 2
        printf("���ڶ�\n");
        break;
    default:
        printf("OTHER\n");
        break;
    }
    return 0;
}
