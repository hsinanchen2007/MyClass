#include <stdio.h>

int main()
{
    // ��ȡ1��100֮�� 7�ı����ĸ���
    // 1.�õ�1~100֮�����е���
    int num = 1;
    int count = 0;
    while(num <= 100){
        // 2.���õ�ǰ�õ�����%7, �������0, ��ô����7�ı���
        if(num % 7 == 0){
            printf("num = %i\n", num); // 1 2 3
            count++;
        }
        num++; // 2 3 4
    }
    printf("count = %i\n", count);
    return 0;
}
