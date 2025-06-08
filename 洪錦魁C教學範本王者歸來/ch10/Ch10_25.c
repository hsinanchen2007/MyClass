/*   程式名稱 : ch10_25.c                 */
/*   字串陣列的應用                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[3][80] = {
         "This is a good book",
         "For C language",
         "By Jiin-Kwei Hung" };

    puts(str[0]);
    puts(str[1]);
    puts(str[2]);
    system("pause");
    return 0;
}
