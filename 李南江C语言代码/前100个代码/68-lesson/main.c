#include <stdio.h>
int say()
{
    lnj:
    printf("say\n");
}

int main()
{
    /*
     * goto����:
     * ��ת��ָ���ı�ǩ
     *
     * ʲô�Ǳ�ǩ?
     * ֻҪ�ں����е�����λ��д�ϱ�ʶ��, Ȼ���ٱ�ʶ���ĺ���д��ð��, ���Ǳ�ǩ
     *
     * ע���:
     * 1.goto������������ת, Ҳ������ǰ����ת
     * 2.����ҵ�����в����򲻵���, ���Ƽ�ʹ��goto
     * 3.gotoֻ����ͬһ����������ת
     */

    /*
    printf("��һ�����\n");
    goto lnj;
    printf("�ڶ������\n");
    // ����һ����ǩ
    lnj:
    printf("���������\n");
    */
    /*
    printf("��һ�����\n");
    lnj:
    printf("�ڶ������\n");
    printf("���������\n");
    goto lnj;
    */

    /*
    int num = 1;
    lnj:
    if(num <= 10){
        printf("num = %i\n", num); // 1 2 3
        num++; // 2 3
        goto lnj;
    }
    */


    printf("main");
    goto lnj;
    return 0;
}
