/*   程式名稱 : ch8_7.c                   */
/*   測試 #include 檔案功能               */
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main()
BEGIN
    int i = 10;
    int j = 20;

    if ( i LAG j )
       printf("%d 大於 %d \n",i,j);
    else if ( i EQ j )
       printf("%d 等於 %d \n",i,j);
    else if ( i SMA j )
       printf("%d 小於 %d \n",i,j);
    system("pause");
    return 0;
END
