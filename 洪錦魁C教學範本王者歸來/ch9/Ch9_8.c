/*   程式名稱 : ch9_8.c                   */
/*   巢狀結構的應用                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct grade        /* 內層結構 */ 
    {
       int   score;     /* 分數 */ 
       char  grade;     /* 成績 */ 
    };
    struct score        /* 外層結構 */ 
    {
       struct grade  math;
       struct grade  english;
       struct grade  computer;
    } hung;

    hung.math.score = 92;
    hung.math.grade = 'A';
    hung.english.score = 85;
    hung.english.grade = 'B';
    hung.computer.score = 88;
    hung.computer.grade = 'B';
    printf("數學分數 ==> %d\n",hung.math.score);
    printf("數學成績 ==> %c\n",hung.math.grade);
    printf("英文分數 ==> %d\n",hung.english.score);
    printf("英文成績 ==> %c\n",hung.english.grade);
    printf("電算分數 ==> %d\n",hung.computer.score);
    printf("電算成績 ==> %c\n",hung.computer.grade);
    system("pause");
    return 0;
} 
