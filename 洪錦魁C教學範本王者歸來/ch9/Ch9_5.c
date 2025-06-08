/*   程式名稱 : ch9_5.c                   */
/*   基本 struct 內包含不同資料型態       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score        /* 定義結構資料名稱 */
    {
       int   math;      /* 數學 */
       int   english;   /* 英文 */
       int   computer;  /* 電腦 */
       float ave;       /* 平均 */ 
       char  sex;       /* 性別 */ 
    } wa;             /* 直接定義變數 */

    wa.math = 80;
    wa.english = 85;
    wa.computer = 83;
    wa.ave = (float) (wa.math+wa.english+wa.computer) / 3.0;
    wa.sex = 'M';
    printf("姓名    性別  數學  英文  電腦  平均 \n");
    printf("王ㄧ郎   %c     %d    %d    %d   %5.2f \n",
            wa.sex,wa.math,wa.english,wa.computer,wa.ave);
    system("pause");
    return 0;
}
