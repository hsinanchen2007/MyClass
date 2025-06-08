/*   程式名稱 : ch16_6.c                  */
/*   連接 2 個鏈結串列                    */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* 列印鏈結串列函數 */ 
void print_list(link pointer)
{
    while ( pointer )
    {
       printf("%d\n",pointer->data);
       pointer = pointer->next;
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
/* 將第二個串列接在第一個串列後面 */
link concatenate(link pointer1, link pointer2)
{
    link tmp;

    tmp = pointer1;
    while ( tmp->next )   /* 將暫時指標指向最後ㄧ個節點   */ 
       tmp = tmp->next;
    tmp->next = pointer2; /* 將最後結點指標指向第二個串列 */ 
    return pointer1;
}
int main()
{
    int arr1[] = { 3, 12, 8, 9, 11};
    int arr2[] = { 21, 30, 33, 44, 38 };
    link  ptr,ptr1,ptr2;

    ptr1 = create_list(arr1,5);
    ptr2 = create_list(arr2,5);
    ptr = concatenate(ptr1,ptr2);
    print_list(ptr);
    system("pause");
    return 0;
}
