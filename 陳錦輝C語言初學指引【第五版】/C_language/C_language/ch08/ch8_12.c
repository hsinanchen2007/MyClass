/*    檔名:ch8_12.c    功能:指標陣列與字串陣列    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int i;
 char *Week[7]= \
 {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
     
 for(i=0;i<=6;i++)
    printf("Week[%d]=%s\n",i,Week[i]);
 /*  system("pause");  */
}
