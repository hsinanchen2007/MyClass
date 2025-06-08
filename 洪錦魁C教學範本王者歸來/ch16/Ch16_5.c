/*   程式名稱 : ch16_5.c                        */
/* 利用一個函數建立鏈結串列再建立一個函數列印它 */
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
int main()
{
    int arr[] = { 3, 12, 8, 9, 11 };
    link  ptr;

    ptr = create_list(arr,5);
    print_list(ptr);
    system("pause");
    return 0;
}
