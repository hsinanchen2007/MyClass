#include <stdio.h>

int main()
{
    // ���� �������������ҳ�ָ��ֵ��λ��
    int nums[5] = {1, 3, 5, 7, 9};
    int key = -5;
//    for(int i = 0; i < 5; i++){
//        if(nums[i] == key){
//            printf("index = %i\n", i);
//            break;
//        }
//    }
    /*
    1.ÿ�ζ�ȡ��mid��Ӧ��ֵ��Ҫ���ҵ�ֵ�Ƚ�
    2.���ȡ����ֵС������Ҫ�ҵ�ֵ, ����min��Ϊmid+1, Ȼ�������¼���Midֵ
    3.���ȡ����ֵ��������Ҫ�ҵ�ֵ, ����max��Ϊmid-1, Ȼ�������¼���midֵ
    4.���min������Max��û���ҵ�, ��ô�Ͳ�������
     */
    int min = 0;
    int len = sizeof(nums) / sizeof(nums[0]);
    int max = len - 1;
    int mid = (min + max) / 2;
    while(min <= max){
        if(nums[mid] > key){
            max = mid - 1;
            mid = (min + max) / 2;
        }else if(nums[mid] < key){
            min = mid + 1;
            mid = (min + max) / 2;
        }else{
            printf("index = %i\n", mid);
            break;
        }
    }
    printf("û���ҵ�\n");
    return 0;
}
