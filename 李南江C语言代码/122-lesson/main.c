#include <stdio.h>
void printMap(char map[6][6], int row, int len);
char lowerCase(char ch);
char getDirection();
int main()
{
    // 1.�����ά���鱣���ͼ
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
    // 2.������ά����, ��ӡ��ͼ
    printMap(map, row, col);

//    // 3.��ʾ�û���������
//    printf("������w a s d����һ���ַ�, ����С���߳��Թ�\n");
//    // 4.������������û����������
//    char ch;
//    // 5.�����û����������
//    scanf("%c", &ch);
//    // 6.ͳһ����ĸת��ΪСд
//    ch = ch + ('a' - 'A');
//    printf("ch = %c\n", ch);

    // 3.��ȡ���ߵķ���
    char ch = getDirection();
    printf("ch = %c\n", ch);
    return 0;
}
// ����ҵ������, ��װ����һ��Ҫ���ص�һԭ��
// ����һ������ֻ��һ������
/**
 * @brief lowerCase  ����д��ĸת��ΪСд��ĸ
 * @param ch  ��Ҫת������ĸ
 * @return  ת��֮�����ĸ
 */
char lowerCase(char ch){
    // 1.�ж��Ƿ��Ǵ�д��ĸ
    if(ch >= 'A' && ch <= 'Z'){
        return ch + ('a' - 'A');
    }
    return ch;
}
/**
 * @brief getDirection ��ȡ���ߵķ���
 * @return  ��ȡ���ķ���
 */
char getDirection(){
    // 1.��ʾ�û���������
    printf("������w a s d����һ���ַ�, ����С���߳��Թ�\n");
    // 2.������������û����������
    char ch;
    // 3.�����û����������
    scanf("%c", &ch);
    // 4.ͳһ����ĸת��ΪСд
    ch = lowerCase(ch);
    // 5.����ȡ�����ݷ��ظ�������
    return ch;
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
