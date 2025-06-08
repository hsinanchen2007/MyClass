/*   程式名稱 : ch16_4.c                  */
/*   反方向列印鏈節串列                   */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
int main()
{
    link  ptr,head,tail;
    int   num,i;

    tail = ( link ) malloc(sizeof(node));
    tail->next = NULL;
    ptr = tail;
    printf("請輸入 5 筆資料 \n");
    for ( i = 0; i <= 4; i++ )
    {
       scanf("%d",&num);
       ptr->data = num;  /* 設定節點值 */
       head = ( link ) malloc(sizeof(node));
       head->next = ptr;/*將新取得的節點指標指向前ㄧ個節點*/ 
       ptr = head;      /* 重設 ptr 的位置 */ 
    }
    ptr = ptr->next;     /* 因為最後取得的節點沒有資料 */
    printf("反序列印串列 \n");
    while ( ptr != NULL )  /* 如果不是指向 NULL 則列印 */
    {
       printf("串列值 %d\n",ptr->data);
       ptr = ptr->next;
    }
    system("pause");
    return 0;
}
