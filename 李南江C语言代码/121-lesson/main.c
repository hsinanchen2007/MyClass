#include <stdio.h>
void printMap(char map[6][6], int row, int len);
int main()
{
    /*
     ######
     #O #
     # ## #
     #  # #
     ##   #
     ######
     */
    // 1.定义二维数组保存地图
    char map[6][6] = {
    {'#', '#', '#', '#', '#', '#'},
    {'#', 'R', ' ', '#', ' ', ' '},
    {'#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#'},
    };
    // sizeof(二维数组名称)得到的是二维数组的总大小
//    int size = sizeof(map);
    // sizeof(二维数组名称[索引])得到的是二维数组中的每一个元素的总大小
//    int size = sizeof(map[1]);
//    printf("size = %i\n", size);

    int row = sizeof(map) / sizeof(map[1]);
    int col = sizeof(map[1]);
    // 2.遍历二维数组, 打印地图
//    for(int i = 0; i < 6; i++){
//        for(int j = 0; j < 6; j++){
//            printf("%c", map[i][j]);
//        }
//        printf("\n");
//    }
    printMap(map, row, col);
    return 0;
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
