/*   程式名稱 : ch10_29.c                 */
/*   main(argc,argv) 的應用               */
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    int i;

    puts("輸出如下");
    for ( i = 0; i < argc; i++ )
       puts(argv[i]);
    system("pause");
    return 0;
}
