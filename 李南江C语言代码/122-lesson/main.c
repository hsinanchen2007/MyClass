#include <stdio.h>
void printMap(char map[6][6], int row, int len);
char lowerCase(char ch);
char getDirection();
int main()
{
    // 1.定义二维数组保存地图
    char map[6][6] = {
    {'#', '#', '#', '#', '#', '#'},
    {'#', 'R', ' ', '#', ' ', ' '},
    {'#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#'},
    };
    int row = sizeof(map) / sizeof(map[1]);
    int col = sizeof(map[1]);
    // 2.遍历二维数组, 打印地图
    printMap(map, row, col);

//    // 3.提示用户输入数据
//    printf("请输入w a s d其中一个字符, 控制小人走出迷宫\n");
//    // 4.定义变量保存用户输入的数据
//    char ch;
//    // 5.接收用户输入的数据
//    scanf("%c", &ch);
//    // 6.统一将字母转换为小写
//    ch = ch + ('a' - 'A');
//    printf("ch = %c\n", ch);

    // 3.获取行走的方向
    char ch = getDirection();
    printf("ch = %c\n", ch);
    return 0;
}
// 在企业开发中, 封装函数一定要遵守单一原则
// 就是一个函数只做一件事情
/**
 * @brief lowerCase  将大写字母转换为小写字母
 * @param ch  需要转换的字母
 * @return  转换之后的字母
 */
char lowerCase(char ch){
    // 1.判断是否是大写字母
    if(ch >= 'A' && ch <= 'Z'){
        return ch + ('a' - 'A');
    }
    return ch;
}
/**
 * @brief getDirection 获取行走的方向
 * @return  获取到的方向
 */
char getDirection(){
    // 1.提示用户输入数据
    printf("请输入w a s d其中一个字符, 控制小人走出迷宫\n");
    // 2.定义变量保存用户输入的数据
    char ch;
    // 3.接收用户输入的数据
    scanf("%c", &ch);
    // 4.统一将字母转换为小写
    ch = lowerCase(ch);
    // 5.将获取的数据返回给调用者
    return ch;
}
/**
 * @brief printMap 用于打印地图
 * @param map 需要打印的二维数组
 * @param row 二维数组的行数 (也就是有多少个一维数组)
 * @param len 二维数组的列数 (也就是一维数组有多少个元素)
 */
void printMap(char map[6][6], int row, int len){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
