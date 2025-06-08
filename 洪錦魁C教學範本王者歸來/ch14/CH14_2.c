/*   程式名稱 : ch14_2.c                  */
/*   刪除檔案                             */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i;

    for ( i = 1; i < argc; i++ )
      unlink(argv[i]);
    system("pause");
    return 0;  
}
