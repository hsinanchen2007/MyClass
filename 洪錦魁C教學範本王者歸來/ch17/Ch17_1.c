/*   程式名稱 : ch17_1.c                  */
/*   push 和 pop 函數應用                 */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;      
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* 將資料放入堆疊 */ 
link push(link stack, int value)
{
    link  newnode;

    newnode = (link) malloc(sizeof(node));
    newnode->data = value; /* 設定新堆疊點的值 */ 
    newnode->next = stack; /*新堆疊指標指向原堆疊頂端*/ 
    stack = newnode;/* 設定指向新堆疊頂端指標  */ 
    return stack;   /* 傳回指向堆疊頂端指標    */
}
/* 由堆疊取得資料 */ 
link pop(link stack, int *value)
{
    link  top;

    top = stack;
    stack = stack->next;
    *value = top->data;   /* 取得堆疊頂端值    */ 
    free(top); /* 釋回原最頂端的堆疊節記憶空間 */ 
    return stack;   /* 傳回指向堆疊頂端指標    */ 
}
int main()
{
    int   arr[] = { 3, 12, 8, 9, 11 };
    link  ptr;
    int   val, i;

    ptr = NULL;
    printf("順序列印整數陣列 \n");
    /* 將陣列資料放入堆疊同時執行列印 */ 
    for ( i = 0; i < 5; i++ )
    {
       ptr = push(ptr,arr[i]);  
       printf("%d\n",arr[i]);
    }
    printf("反向列印原整數陣列 \n");
    /* 取得堆疊資料同時執行列印 */ 
    for ( i = 0; i < 5; i++ )
    {
       ptr = pop(ptr,&val);
       printf("%d\n",val);
    }
    system("pause");
    return 0;
}
