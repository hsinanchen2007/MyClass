#include <stdio.h>

int main() {
    float radius, area;
    
    printf("请输入半径值： ");
    scanf("%f", &radius); //输入半径
    area = 3.14 * radius * radius;
    printf("area=%f\n", area); //输出圆的面积

    return 0;
}