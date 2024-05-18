
#include <stdio.h>

//获取栈内存
int *  GetStackPointer()
{
    int a = 100;//栈内存
    return  &a;
}//这段栈内存就被销毁了，里面的100自然也被销毁


//获取堆内存
int* GetHeapPointer()
{
    int* p = (int*)malloc(sizeof(int));
    *p = 100;
     return p; 
}

int main()
{
     int* pStack = GetStackPointer();

     int* pHeap= GetHeapPointer();

     printf("%d   %d\n", *pStack, *pHeap);
}  

