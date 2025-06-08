/*   程式名稱 : ch9_6.c                   */
/*   struct 初值設定                      */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score        /* 定義結構資料名稱 */
    {
       int   math;      /* 數學 */
       int   english;   /* 英文 */
       int   computer;  /* 電腦 */
       char  sex;       /* 性別 */ 
    } ;             
    struct score wa = { 80, 85, 83, 'M' };

    printf("姓名    性別  數學  英文  電腦  \n");
    printf("王ㄧ郎   %c     %d    %d    %d   \n",
            wa.sex,wa.math,wa.english,wa.computer);
    system("pause");
    return 0;
}
