/*   程式名稱 : ch8_2.c                   */
/*   另ㄧ個 #define 應用                  */
#include <stdio.h>
#include <stdlib.h>
#define   PI   3.1415926    /* 定義圓周率 */ 
#define   R    3.0          /* 定義半徑   */ 

int main()
{
    float  area,circle;

    area = PI * R * R;
    circle = 2 * PI * R;

    printf("圓面積 = %8.4f\n",area);
    printf("圓周長 = %8.4f\n",circle);
    system("pause");
    return 0;
}
