/*   �{���W�� : ch11_11.c                 */
/*   struct �ŧi������O�줸            */
#include <stdio.h>
#include <stdlib.h>
struct pack_field           /* ���c�ŧi   */     
{
   unsigned  int  f1:1;     /* �� 1 �줸  */ 
   unsigned  int  f2:1;     /* �� 1 �줸  */
   unsigned  int  f3:1;     /* �� 1 �줸  */
   unsigned  int  type:2;   /* �� 2 �줸  */
   unsigned  int  index:3;  /* �� 3 �줸  */ 
};
int main()
{
    struct  pack_field  var1;

    printf("�п�J 8 �줸 16�i���� ==> ");
    scanf("%2x",&var1);
    printf("field 1 = %x\n",var1.f1);
    printf("field 2 = %x\n",var1.f2);
    printf("field 3 = %x\n",var1.f3);
    printf("type    = %x\n",var1.type);
    printf("index   = %x\n",var1.index);
    system("pause");
    return 0;
}
