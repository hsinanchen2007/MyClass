#include <stdio.h>

int main() {
    int num = 153;
    int bai = num / 100;
    int shi = num % 100 / 10;//int shi = num / 10 % 10;
    int ge = num % 10;

    printf("百位为：%d\n", bai);
    printf("十位为：%d\n", shi);
    printf("个位为：%d\n", ge);
    
    return 0;
}