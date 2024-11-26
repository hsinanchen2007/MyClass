#include <stdio.h>

int main()
{
    /*
     * switch选择结构
     *
     * 格式:
     * switch(表达式){
     *    case 常量表达式:
     *         被常量表达式控制的语句;
     *         break;
     *    case 常量表达式:
     *         被常量表达式控制的语句;
     *         break;
     *    default:
     *         被default控制的语句;
     *         break;
     * }
     *
     * 特点:
     * 1.众多case和default只有一个会被执行, 并且只会被执行一次
     * 2.会从上至下依次判断每一个表达式的值是否和switch表达式的值相等, 如果相等, 就执行后面的代码
     * 如果不相等, 就继续判断其它的case, 如果所有case都不相等, 那么就执行default后面的代码
     */

    int day = 3;
    switch(day){
    case 1: // day == 1
        printf("星期一\n");
        break;
    case 2: // day == 2
        printf("星期二\n");
        break;
    default:
        printf("OTHER\n");
        break;
    }
    return 0;
}
