#include <stdio.h>
void change(int values[2][3]);
void change2(int values[3]);
int main()
{
    /*
     * 1.�����������ͺͺ���
     * �ں������޸��β�, ����Ӱ�쵽���ʵ��
     *
     * 2.һά����ͺ���
     * �ں������޸��β�, ��Ӱ�쵽���ʵ��
     *
     * 3.��ά����ͺ���
     * �ں������޸��β�, ��Ӱ�쵽���ʵ��
     *
     * �ܽ�:
     * �Ժ�Ҫ��֪���ں������޸��βλ᲻��Ӱ�쵽����ʵ��, �ǲ��ǿ�һ�´��ݵ��ǲ��ǵ�ַ�Ϳ�����
     * ������ݵ��ǵ�ַ, ��ô�ں������޸��β�, ��Ӱ�쵽���ʵ��
     */
    int nums[2][3] = {
        {1, 3, 5},
        {2, 4, 6}
    };
//    printf("nums[0][1] = %i\n", nums[0][1]);
//    change(nums);
//    printf("nums[0][1] = %i\n", nums[0][1]);

//    printf("&nums[0] = %p\n", &nums[0]);
//    printf("nums[0] = %p\n", nums[0]);

    printf("nums[0][1] = %i\n", nums[0][1]);
    change2(nums[0]);
    printf("nums[0][1] = %i\n", nums[0][1]);
    return 0;
}
void change2(int values[3]){
    values[1] = 777;
}

void change(int values[2][3]){
    values[0][1] = 666;
}
