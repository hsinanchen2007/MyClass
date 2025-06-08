/*   程式名稱 : ch8_5.c                   */
/*   #define 應用 5                       */
#include <stdio.h>
#include <stdlib.h>
#define   BEGIN   {
#define   END     }

int main()
BEGIN
    int i;

    for ( i = 0; i < 3; i++ )
    BEGIN
       printf("模擬 Pascal begin 和 end.\n");
       printf("BEGIN 是 { \n");
       printf("END   是 } \n");
    END
    system("pause");
    return 0;
END
