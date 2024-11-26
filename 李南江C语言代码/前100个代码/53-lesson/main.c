#include <stdio.h>

int main()
{
    /*
    要求用户输入一个分数，根据输入的分数输出对应的等级
    A 90～100
    B 80～89
    C 70～79
    D 60～69  60 / 10 = 6; 69 / 10 = 6
    E 0～59
     */
    // 1.提示用户如何输入
    printf("请输入一个0~100的分数,以回车结束\n");
    // 2.定义变量保存用户输入
    int score;
    // 3.接收用户输入
    scanf("%i", &score);
    // 4.判断分数, 输出结果
    // 4.1排除非法数据
    /*
    if(score < 0 || score > 100){
        printf("没有这个分数\n");
    }else if(score >= 90 && score <= 100){
        printf("当前的分数是%i,对应的等级是A", score);
    }else if(score >= 80 && score <= 89){
        printf("当前的分数是%i,对应的等级是B", score);
    }else if(score >= 70 && score <= 79){
        printf("当前的分数是%i,对应的等级是C", score);
    }else if(score >= 60 && score <= 69){
        printf("当前的分数是%i,对应的等级是D", score);
    }else{
         printf("当前的分数是%i,对应的等级是E", score);
    }
    */
    switch(score / 10){
    case 10:
//         printf("当前的分数是%i,对应的等级是A", score);
//        break;
    case 9:
         printf("当前的分数是%i,对应的等级是A", score);
        break;
    case 8:
        printf("当前的分数是%i,对应的等级是B", score);
        break;
    case 7:
        printf("当前的分数是%i,对应的等级是C", score);
        break;
    case 6:
        printf("当前的分数是%i,对应的等级是D", score);
        break;
    case 5:
//        printf("当前的分数是%i,对应的等级是E", score);
//        break;
    case 4:
//        printf("当前的分数是%i,对应的等级是E", score);
//        break;
    case 3:
//        printf("当前的分数是%i,对应的等级是E", score);
//        break;
    case 2:
//        printf("当前的分数是%i,对应的等级是E", score);
//        break;
    case 1:
//        printf("当前的分数是%i,对应的等级是E", score);
//        break;
    case 0:
        printf("当前的分数是%i,对应的等级是E", score);
        break;
    default:
        printf("没有这个分数\n");
        break;
    }
    return 0;
}
