#include <stdio.h>

int main()
{
    // 1.单行注释可以嵌套单行注释
    // 被注释的内容 // 被注释的内容

    // 2.多行注释可以嵌套单行注释
    /*
     // 被注释的内容
     */

    // 3.单行注释可以嵌套多行注释, 但是被嵌套的多行注释必须在同一行
    // /**/

    // 4.多行注释不能嵌套多行注释
//     /*
//     /*
//     */
//     */
    return 0;
}
