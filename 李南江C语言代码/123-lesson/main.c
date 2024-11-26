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

    do{
        // 3.��ȡ���ߵķ���
        char ch = getDirection();

        // 4.��С�˶�����
        move(ch, map);

        // 5.������ά����, ��ӡ��ͼ
        printMap(map, row, col);

        // 6.�ж���û���ߵ�����
        if(startRow == endRow && startCol == endCol){
            break;
        }
    }while(1);
    printf("��ϲ��, �Ѿ��߳����Թ�\n");
    return 0;
}
/**
 * @brief move С���ƶ�����
 * @param ch ��Ҫ�ƶ��ķ���
 * @param map ����С�˵ĵ�ͼ
 */
void move(char ch, char map[6][6]){
    switch(ch){
    case 'w':
//        printf("������\n");
        // �ж����ߵķ����ǲ���ǽ��, ������Ǿ�����
        if(map[startRow - 1][startCol] != '#'){
            // ��յ�ǰ��λ��
            map[startRow][startCol] = ' ';
            // ����һ�б��С��
            map[startRow - 1][startCol] = 'R';
            // �޸�С�˵�ǰ��λ��Ϊ����֮���λ��
            startRow = startRow - 1;
        }
        break;
    case 's':
//        printf("������\n");
        // �ж����ߵķ����ǲ���ǽ��, ������Ǿ�����
        if(map[startRow + 1][startCol] != '#'){
            // ��յ�ǰ��λ��
            map[startRow][startCol] = ' ';
            // ����һ�б��С��
            map[startRow + 1][startCol] = 'R';
            // �޸�С�˵�ǰ��λ��Ϊ����֮���λ��
            startRow = startRow + 1;
        }
        break;
    case 'a':
//        printf("������\n");
        // �ж����ߵķ����ǲ���ǽ��, ������Ǿ�����
        if(map[startRow][startCol - 1] != '#'){
            // ��յ�ǰ��λ��
            map[startRow][startCol] = ' ';
            // ����һ�б��С��
            map[startRow][startCol - 1] = 'R';
            // �޸�С�˵�ǰ��λ��Ϊ����֮���λ��
            startCol = startCol - 1;
        }
        break;
    case 'd':
//        printf("������\n");
        // �ж����ߵķ����ǲ���ǽ��, ������Ǿ�����
        if(map[startRow][startCol + 1] != '#'){
            // ��յ�ǰ��λ��
            map[startRow][startCol] = ' ';
            // ����һ�б��С��
            map[startRow][startCol + 1] = 'R';
            // �޸�С�˵�ǰ��λ��Ϊ����֮���λ��
            startCol = startCol + 1;
        }
        break;
    default:
        printf("û���������\n");
    }
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
    // ������뻺����
    setbuf(stdin, NULL);
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
    // �����Ļ
    system("cls");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
