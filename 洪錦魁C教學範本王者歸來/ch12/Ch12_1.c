/*   祘Α嘿 : ch12_1.c                  */
/*   璸衡璣ゅダ籔┰计计       */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    char ch;
    printf("叫块ヴ種璣ゅダ┪计\n"); 
    while ( ( ch = getche() ) != '\r' )
       isalnum(ch) ? (count++) : ( count=count );
    printf("\n");   
    printf("璣ゅダ籔┰计计 = %d\n",count);
    system("pause");
    return 0;
}
