
#include <stdio.h>

int main()
{
     //使用for语句听10遍歌曲

    //i=0 只执行一次 , 
    //i<=10每次都会执行，满足条件就执行语句块
    //i++每次都会执行，在语句块执行完毕后执行
    for (int i = 1; i <= 10; ++i)
    {
        printf("第%d次播放歌曲!\n",i);
    }


    printf("\n\n");

    //while循环
    int j = 1;
    while (j <= 10) //条件为真则循环
    {
        printf("第%d次播放歌曲!\n", j);

        ++j; //让次数加1
    }

    printf("\n\n");

    //do while循环
    int k = 1;
    do
    {
        printf("第%d次播放歌曲!\n", k); 
    } 
    while (++k <= 10);

}