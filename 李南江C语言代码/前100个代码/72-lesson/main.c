#include <stdio.h>

int main()
{
    /*
     ����:
     *
     **
     ***
     ****

     ****
     ****
     ****
     ****

     ����:
     ����ҵ������, ��⳯��, ��Ҫ�޸���ѭ�����������ʽ������ѭ���ı���
     */

//    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
//        count++;
        printf("\n");
    }
    return 0;
}
