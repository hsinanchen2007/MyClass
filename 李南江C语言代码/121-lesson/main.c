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
    // 1.�����ά���鱣���ͼ
    char map[6][6] = {
    {'#', '#', '#', '#', '#', '#'},
    {'#', 'R', ' ', '#', ' ', ' '},
    {'#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#'},
    };
    // sizeof(��ά��������)�õ����Ƕ�ά������ܴ�С
//    int size = sizeof(map);
    // sizeof(��ά��������[����])�õ����Ƕ�ά�����е�ÿһ��Ԫ�ص��ܴ�С
//    int size = sizeof(map[1]);
//    printf("size = %i\n", size);

    int row = sizeof(map) / sizeof(map[1]);
    int col = sizeof(map[1]);
    // 2.������ά����, ��ӡ��ͼ
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
 * @brief printMap ���ڴ�ӡ��ͼ
 * @param map ��Ҫ��ӡ�Ķ�ά����
 * @param row ��ά��������� (Ҳ�����ж��ٸ�һά����)
 * @param len ��ά��������� (Ҳ����һά�����ж��ٸ�Ԫ��)
 */
void printMap(char map[6][6], int row, int len){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
