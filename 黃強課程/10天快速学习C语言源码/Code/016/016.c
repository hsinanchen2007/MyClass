
#include <stdio.h>

int main()
{
    int scores[1000] = {0};//用于存放学生的成绩,把数组中每个元素初始化为0

    //下标索引从0开始
    scores[0] = 100; //为第一个学生填充成绩
    scores[1] = 99;
    scores[2] = 98;

    for (int i = 0; i < 1000; ++i) //为什么从0开始，因为方便下标索引
    {
        printf("第%d个学生的成绩 %d\n", i + 1, scores[i]);
    }

    printf("scores[1000]的内存大小  %d 字节\n", sizeof(scores));


    //数组定义的时候不指定长度
    int arr[] = { 100,200,300}; //通过初始值自动推导长度为3
    printf("arr[] 的内存大小  %d 字节\n", sizeof(arr));

}