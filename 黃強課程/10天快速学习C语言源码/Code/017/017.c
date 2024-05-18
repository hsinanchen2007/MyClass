#include <stdio.h>

int main()
{
    //定义二维数组，全部默认初始化为0
    int scores[100][50] = {0};

    //为数组第一行赋值
    scores[0][0] = 100;//为第一行第一列的元素赋值
    scores[0][1] = 99;//为第一行第二列的元素赋值
    scores[0][2] = 98;//为第一行第三列的元素赋值

    //为数组第二行赋值
    scores[1][0] = 88;//为第二行第一列的元素赋值
    scores[1][1] = 77;//为第二行第二列的元素赋值
    scores[1][2] = 66;//为第二行第三列的元素赋值


    //为最后一个元素赋值
    scores[99][49] = 111;

    //打印二维数组的值
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    printf("scores[100][50]占的内存是%d\n", sizeof(scores));

}
