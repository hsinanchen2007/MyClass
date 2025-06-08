/*   程式名稱 : ch16_8.c                  */
/*   由小到大列出鏈結串列值               */
/*   本程式在刪除節點時增加 free() 動作   */ 
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* 刪除鏈結串列的結點 */ 
link delete_node(link pointer, link tmp)
{
    link deletenode;
    
    if ( tmp == NULL )                /* 刪除第一個節點   */
    {
       tmp = pointer->next;
       free(pointer);
       return tmp;
    }   
    else
    {
       if ( tmp->next->next == NULL ) /* 刪除最後ㄧ個節點 */
       {
          deletenode = tmp->next;
          tmp->next = NULL;
          free(deletenode);
       }   
       else                           /* 刪除其它節點     */
       {
          deletenode = tmp->next;
          tmp->next = tmp->next->next;
          free(deletenode);
       }   
       return pointer;
    }
}
void selection_sort(link pointer, int num)
{
    link tmp, btmp;
    int  i, min;

    for ( i = 0; i < num; i++ )
    {
       tmp = pointer;
       min = tmp->data;
       btmp = NULL; /* 暫時設定未來將指向最小值節點 */ 
       while ( tmp->next )
       {
          if ( min > tmp->next->data )
          {
             min = tmp->next->data;
             btmp = tmp;     /* 指向最小值節點 */
          }
          tmp = tmp->next;
       }
       printf("%d\n",min);   /* 列印最小值 */ 
       pointer = delete_node(pointer,btmp);
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
int main()
{
    int arr[] = { 3, 12, 8, 9, 11};
    link  ptr;

    ptr = create_list(arr,5);
    selection_sort(ptr,5);
    system("pause");
    return 0;
}
