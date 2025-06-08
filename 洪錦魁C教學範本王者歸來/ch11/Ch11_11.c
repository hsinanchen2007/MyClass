/*   程式名稱 : ch11_11.c                 */
/*   struct 宣告資料欄位是位元            */
#include <stdio.h>
#include <stdlib.h>
struct pack_field           /* 結構宣告   */     
{
   unsigned  int  f1:1;     /* 佔 1 位元  */ 
   unsigned  int  f2:1;     /* 佔 1 位元  */
   unsigned  int  f3:1;     /* 佔 1 位元  */
   unsigned  int  type:2;   /* 佔 2 位元  */
   unsigned  int  index:3;  /* 佔 3 位元  */ 
};
int main()
{
    struct  pack_field  var1;

    printf("請輸入 8 位元 16進位整數 ==> ");
    scanf("%2x",&var1);
    printf("field 1 = %x\n",var1.f1);
    printf("field 2 = %x\n",var1.f2);
    printf("field 3 = %x\n",var1.f3);
    printf("type    = %x\n",var1.type);
    printf("index   = %x\n",var1.index);
    system("pause");
    return 0;
}
