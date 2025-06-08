/*   program name : ch13_14.c             */
/*   fread() 的應用                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    struct score
    {
       int math;           /* 數學成績 */
       char  name[10];     /* 姓名欄位 */
    }  var;

    fp = fopen("sam13.txt","rb");
    /* 若不是讀到檔案末端則繼續讀 */ 
    while ( fread(&var,sizeof(var),1,fp) != 0 )
    {
       printf("姓名     : %s\n",var.name);
       printf("數學成績 : %d\n",var.math);
    }  
    fclose(fp);
    system("pause");
    return 0;
}
