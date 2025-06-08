/*   程式名稱 : ch16_9.c                  */
/*   先泡沫排序再執行插入節點             */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* 將節點插在排序串列內 */ 
link insert_node(link pointer, link tmp, int value)
{
    link newnode;
    if ( tmp == NULL )  /* 新結點插在第ㄧ個節點前面 */
    {
       newnode = (link) malloc(sizeof(node));
       newnode->data = value;   /* 設定新結點值 */ 
       newnode->next = pointer; /* 新結點指標指向串列第ㄧ個節點*/ 
       return newnode;
    }
    else
    {
       if ( tmp->next == NULL ) 
       {       /* 新結點插在最後ㄧ個節點後面 */ 
          newnode = (link) malloc(sizeof(node));
          newnode->data = value; /* 設定新結點值 */
          tmp->next = newnode; /*串列最後ㄧ個節點指標指向新結點*/ 
          newnode->next = NULL;
       }
       else    /* 新結點插在鏈結串列tmp指標後面 */
       {
          newnode = (link) malloc(sizeof(node));
          newnode->data = value; /* 設定新結點值 */
          newnode->next = tmp->next;
          tmp->next = newnode; /* tmp指標指向新結點 */ 
       }
       return pointer;
    }
}
/* 搜尋插入串列的位置 */ 
link search_insert_location(link pointer, int value)
{
    link  tmp,btmp;
    int   i, min;
    int   OTRUE = 1;

    tmp = pointer;
    btmp = NULL;
    while ( tmp && OTRUE )
    {
       if ( value < tmp->data )
          OTRUE = 0;  /* 找到欲插入的點立刻離開迴路 */ 
       if ( OTRUE )
       {
          btmp = tmp;
          tmp = tmp->next;
       }
    }
    /* 如果 btmp 是 NULL 則是插再串列第一個節點前面 */
    /* 否則插在 btmp 所指節點的下ㄧ個位置           */ 
    pointer = insert_node(pointer,btmp,value);
    return pointer;
}
/* 將鏈節串列由小排到大 */ 
void bubble_sort(link pointer, int num)
{
    link tmp;
    int  i, j, value;

    for ( i = 1; i < num; i++ )
    {
       tmp = pointer;
       for ( j = 1; j < num; j++ )
       {
          if ( tmp->data > tmp->next->data )
          {  /* 如果前ㄧ筆大於下ㄧ筆則對調節點值 */ 
             value = tmp->data;
             tmp->data = tmp->next->data;
             tmp->next->data = value;
          }
          tmp = tmp->next; /* 移動暫時指標至下ㄧ節點 */ 
       }
    }
}
/* 將陣列轉成鏈結串列函數 */
link create_list(int array[],int num)
{
    link tmp1,tmp2,pointer;
    int  i;
/* pointer 指向串列的第一個節點 */ 
    pointer = ( link ) malloc(sizeof(node));
    pointer->data = array[0]; /* 第一筆資料   */ 
    tmp1 = pointer;           /* 移動暫時指標 */ 
    for ( i = 1; i < num; i++ )
    {
       tmp2 = (link) malloc(sizeof(node));
       tmp2->next = NULL;
       tmp2->data = array[i];
       tmp1->next = tmp2;     /* 舊節點指標指向新節點 */ 
       tmp1 = tmp1->next;     /* 移動暫時指標 */
    }
    return pointer;
}
/* 列印鏈結串列函數 */
void print_list(link pointer)
{
    while ( pointer )
    {
       printf("%d\n",pointer->data);
       pointer = pointer->next;
    }
}
int main()
{
    int arr[] = { 3, 12, 8, 9, 11 };
    link  ptr;

    ptr = create_list(arr,5);
    bubble_sort(ptr,5);
    printf("插入節點前先執行列印 \n");
    print_list(ptr);
    ptr = search_insert_location(ptr,15);
    printf("插入節點 15 再列印 \n");
    print_list(ptr);
    ptr = search_insert_location(ptr,7);
    printf("插入節點 7  再列印 \n");
    print_list(ptr);
    system("pause");
    return 0;
}
