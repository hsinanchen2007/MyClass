#include <stdio.h>

int main()
{
    /*
     * breakע���:
     * 1.break���ֻ������switch����ѭ�����, �뿪���������û���κε�����
     * 2.break���ĺ��治�ܱ�д����, ��Ϊִ�в���
     *
     * break��switch�е�����:
     * ��������switch���
     *
     * break��ѭ������е�����:
     * ����������ǰ��ѭ�����
     */

    /*
    switch(2){
    case 1:
        printf("����1\n");
        break;
    case 2:
        printf("����2\n");
        break;
        printf("123\n");
    default:
        printf("other\n");
    }
    */

    for(int i = 0; i < 10; i++){
        printf("i = %i\n", i);
        break;
        printf("123\n");
    }

    if(1){
        break; // ����, �뿪switch��ѭ��û������, ����ʹ��
    }
    return 0;
}
