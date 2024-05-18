#include <stdio.h>

int main()
{
    
    //continue只停止本次循环，继续从下一次开始循环
    for (int i = 1; i <= 100; ++i)
    {
        if (i == 10) continue; //第10首歌曲不好听，跳过
  
        printf("播放第%d首歌曲！\n", i);
    }

    printf("\n\n");

    //break语句 直接跳出循环
    for (int j= 1; j<= 100; ++j)
    {
        if ( j== 10)  break; //到第10首歌了就不听了

        printf("播放第%d首歌曲！\n", j);
    }

    //goto  语句，直接跳转到指定的位置

    BBB:
    for (int k = 1; k <= 100; ++k)
    {
        if (k== 10)   goto BBB; //到第10首歌了就跳到第一首歌曲

        printf("播放第%d首歌曲！\n", k);
    }


}
