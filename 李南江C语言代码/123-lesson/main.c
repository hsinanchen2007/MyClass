#include <stdio.h>
void printMap(char map[6][6], int row, int len);
char lowerCase(char ch);
char getDirection();
void move(char ch, char map[6][6]);
int startRow = 1;
int startCol = 1;
int endRow = 1;
int endCol = 5;
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

    do{
        // 3.获取行走的方向
        char ch = getDirection();

        // 4.让小人动起来
        move(ch, map);

        // 5.遍历二维数组, 打印地图
        printMap(map, row, col);

        // 6.判断有没有走到出口
        if(startRow == endRow && startCol == endCol){
            break;
        }
    }while(1);
    printf("恭喜您, 已经走出了迷宫\n");
    return 0;
}
/**
 * @brief move 小人移动方法
 * @param ch 需要移动的方向
 * @param map 保存小人的地图
 */
void move(char ch, char map[6][6]){
    switch(ch){
    case 'w':
//        printf("向上走\n");
        // 判断行走的方向是不是墙壁, 如果不是就行走
        if(map[startRow - 1][startCol] != '#'){
            // 清空当前的位置
            map[startRow][startCol] = ' ';
            // 让上一行变成小人
            map[startRow - 1][startCol] = 'R';
            // 修改小人当前的位置为行走之后的位置
            startRow = startRow - 1;
        }
        break;
    case 's':
//        printf("向下走\n");
        // 判断行走的方向是不是墙壁, 如果不是就行走
        if(map[startRow + 1][startCol] != '#'){
            // 清空当前的位置
            map[startRow][startCol] = ' ';
            // 让上一行变成小人
            map[startRow + 1][startCol] = 'R';
            // 修改小人当前的位置为行走之后的位置
            startRow = startRow + 1;
        }
        break;
    case 'a':
//        printf("向左走\n");
        // 判断行走的方向是不是墙壁, 如果不是就行走
        if(map[startRow][startCol - 1] != '#'){
            // 清空当前的位置
            map[startRow][startCol] = ' ';
            // 让上一行变成小人
            map[startRow][startCol - 1] = 'R';
            // 修改小人当前的位置为行走之后的位置
            startCol = startCol - 1;
        }
        break;
    case 'd':
//        printf("向右走\n");
        // 判断行走的方向是不是墙壁, 如果不是就行走
        if(map[startRow][startCol + 1] != '#'){
            // 清空当前的位置
            map[startRow][startCol] = ' ';
            // 让上一行变成小人
            map[startRow][startCol + 1] = 'R';
            // 修改小人当前的位置为行走之后的位置
            startCol = startCol + 1;
        }
        break;
    default:
        printf("没有这个方向\n");
    }
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
    // 清空输入缓冲区
    setbuf(stdin, NULL);
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
    // 清空屏幕
    system("cls");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
