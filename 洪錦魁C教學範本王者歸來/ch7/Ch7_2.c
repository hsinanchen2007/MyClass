/*   程式名稱 : ch7_2.c                   */
/*   auto 變數於不同函數的應用            */
#include <stdio.h>
#include <stdlib.h>
void fun1()
{
    int i = 1;     /* 雖未宣告仍屬 auto 變數 */ 
    printf("fun1 函數 i = %d\n",i);
}
void fun2()
{
    int i = 2;     /* 雖未宣告仍屬 auto 變數 */
    printf("fun2 函數 i = %d\n",i);
}
int main()
{
    int  i = 0;
    printf("Main 主程式 i = %d \n",i);
    fun1();
    fun2();
    printf("Main 主程式 i = %d \n",i);
    fun1();
    fun2();
    system("pause");
    return 0;
}
