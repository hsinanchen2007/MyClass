 
#include <stdio.h>

int main()
{
    int  a = 100;//栈内存，系统自动分配

    printf("栈内存变量a  %d\n", a);
  
    int* p = (int*)malloc(sizeof(int));  //堆内存，程序员手动分配的

    *p = 200;//使用堆内存

    printf("堆内存上的内容  %d\n", *p);

    free(p);//程序员手动释放堆内存, 如果忘记释放就会导致内存泄漏

} //变量a的栈内存，自动被释放