/*   程式名稱 : ch6_2.c                   */
/*   基本函數呼叫                         */
#include <stdio.h>
#include <stdlib.h>
output()
{
    printf("Hello!\n");
    printf("How are you?\n");
}
int main()
{
    int i;

    for ( i = 0; i < 3; i++ )
       output();
    system("pause");
    return 0;   
}
