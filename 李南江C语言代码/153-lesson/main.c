#include <stdio.h>
// �����ڴ�������: ȫ��������
enum Gender{
    male,
    femal
};
void test();
int main()
{
    /*
     * 1.ö������������
     * �ͽṹ��һ����Ϊ�ֲ��������ȫ��������
     *
     * 2.ö�ٱ����Ķ��ֶ����ʽ
     * �ͽṹ��һ����Ϊ:
     * 2.1�ȶ���ö������, �ٶ���ö�ٱ���
     * 2.2����ö�����͵�ͬʱ����ö�ٱ���
     * 2.3����ö�����͵�ͬʱ����ö�ٱ���, ����ʡ��ö����������
     */
    /*
    {
        // �����ڴ�����: �ֲ�������
        enum Gender{
            male,
            femal
        };
        enum Gender g1 = male;
    }
    enum Gender g2 = male; // ����
    */

    enum Gender g1 = male;


    // 1.�ȶ���ö������, �ٶ���ö�ٱ���
    /*
    enum Gender{
        male,
        femal
    };
    enum Gender g;
    */

    // 2.����ö�����͵�ͬʱ����ö�ٱ���
    /*
    enum Gender{
        male,
        femal
    } g;
    */

    // 3.����ö�����͵�ͬʱ����ö�ٱ���, ����ʡ��ö����������
    /*
    enum{
        male,
        femal
    } g;
    */
}
void test(){
    enum Gender g2 = male;
}
