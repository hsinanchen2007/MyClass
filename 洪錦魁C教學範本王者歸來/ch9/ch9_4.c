/*   程式名稱 : ch9_4.c                   */
/*   基本 struct 應用 3                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score      /* 定義結構資料名稱 */
    {
       int math;      /* 數學 */
       int english;   /* 英文 */
       int computer;  /* 電腦 */
    } hung, chen;     /* 直接定義變數 */ 

    hung.math = 80;
    hung.english = 85;
    hung.computer = 83;
    chen.math = 75;
    chen.english = 91;
    chen.computer = 88;
    printf("姓名      數學     英文     電腦 \n");
    printf("洪予柔     %d       %d       %d   \n",
            hung.math,hung.english,hung.computer);
    printf("陳盛昌     %d       %d       %d   \n",
            chen.math,chen.english,chen.computer);
    system("pause");
    return 0;
}
