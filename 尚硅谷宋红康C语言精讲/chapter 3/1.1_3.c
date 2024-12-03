#include <stdio.h>

int main() {
    int hours = 89;
    int day = hours / 24;
    int hour = hours % 24;

    printf("为抵抗洪水，战士连续作战%d小时：是%d天%d小时\n",hours,day,hour);
    
    return 0;
}