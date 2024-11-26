#include <stdio.h>

int main()
{
    /*
     * 1.十进制转二进制
     * 规律: 除二倒叙取余
     *

     14
      2
     ---
      7    0
      2
     ---
      3    1
      2
     ---
      1    1
      2
     ---
      0    1
     */
    int num = 0b1110;
    printf("num = %i\n", num);
    return 0;
}
