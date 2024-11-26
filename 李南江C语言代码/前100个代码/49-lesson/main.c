#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    /*
     * 猜拳游戏规则:
     * 0代表石头, 1代表剪刀, 2代表布
     * 电脑        用户(输了)     用户(赢了)
     * 0代表石头    1代表剪刀     2代表布
     * 1代表剪刀    2代表布       0代表石头
     * 2代表布      0代表石头     1代表剪刀
     *
     * // 赢了
     * 0 - 2 = -2
     * 1 - 0 = 1
     * 2 - 1 = 1
     *
     * // 输了
     * 0 - 1 = -1
     * 1 - 2 = -1
     * 2 - 0 = 2
     */

    // 1.让电脑随机出拳
    srand(time(NULL));
    // 注意点: C语言提供的 rand()函数 默认是一个伪随机数
    /*
     * 0 % 3 = 0
     * 1 % 3 = 1
     * 2 % 3 = 2
     *
     * 3 % 3 = 0
     * 4 % 3 = 1
     * 5 % 3 = 2
     * 6 % 3 = 0
     */
    int cm = rand() % 3;
    printf("cm = %i\n", cm);

    // 2.让用户出拳
    // 2.1提示用户如何输入
    printf("请输入一个0~2的整数, 以回车结束\n");
    printf("0代表石头, 1代表剪刀, 2代表布\n");
    // 2.2定义变量保存用户的输入
    int user;
    // 2.3接收用户的输入
    scanf("%i", &user);
    // 3.判断电脑和用户出拳
    // 3.1排出非法数据
    /*
    if(user < 0 || user > 2){
        printf("还能不能好好的玩耍\n");
    }
    // 3.2判断出拳, 输出结果
    else if((cm == 0 && user == 2) ||
            (cm == 1 && user == 0) ||
            (cm == 2 && user == 1)){
        // 赢了
        printf("电脑出的是%i, 用户出的是%i, 用户赢了\n", cm, user);
    }else if((cm == 0 && user == 1) ||
             (cm == 1 && user == 2) ||
             (cm == 2 && user == 0)){
        // 输了
        printf("电脑出的是%i, 用户出的是%i, 用户输了\n", cm, user);
    }else{
        // 平手
        printf("电脑出的是%i, 用户出的是%i, 打平了\n", cm, user);
    }
    */

    if(user < 0 || user > 2){
        printf("还能不能好好的玩耍\n");
    }else{
        // 用电脑的出拳 - 用户的出拳
        int temp = cm - user;
        if(temp == -2 || temp == 1){
             printf("电脑出的是%i, 用户出的是%i, 用户赢了\n", cm, user);
        }else if(temp == -1 || temp == 2){
             printf("电脑出的是%i, 用户出的是%i, 用户输了\n", cm, user);
        }else{
             printf("电脑出的是%i, 用户出的是%i, 打平了\n", cm, user);
        }
    }
    return 0;
}
