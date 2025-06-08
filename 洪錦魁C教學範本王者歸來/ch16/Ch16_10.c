/*   程式名稱 : ch16_10.c                 */
/*   雙向鏈結串列的基本應用               */
#include <stdlib.h>
#include <stdio.h>
struct list           /* 雙向鏈結串列宣告 */ 
{
    int         data;
    struct list *front;  /* 指向下ㄧ個節點 */ 
    struct list *back;   /* 指向前ㄧ個節點 */ 
};
typedef struct list node;
typedef node *link;

int main()
{
    link  ptr,tail,head;
    int   num, i;
/* tail 指向第ㄧ個建的節點 */ 
    tail = ( link ) malloc(sizeof(node));
    tail->back = NULL;
    tail->front = NULL;
    ptr = tail; /*由於第一次建節點所以ptr和tail指向相同位置*/ 
    printf("請輸入 5 筆資料 \n");
    for ( i = 0; i < 5; i++ )
    {
       scanf("%d",&num);
       ptr->data = num;
/* ptr 未來將指向最後所建的節點 */       
       head = (link) malloc(sizeof(node));
       if ( i != 4 )
       {
          head->back = ptr;
          head->front = NULL;
          ptr->front = head;
          ptr = head;   /* ptr 指向最後所建的節點 */ 
       }
    }
    printf("反向列印雙向鏈結串列\n");
    while ( ptr )
    {
       printf("串列值 ==> %d\n",ptr->data);
       ptr = ptr->back;
    }
    printf("順序列印雙向鏈結串列\n");
    ptr = tail;
    while ( ptr )
    {
       printf("串列值 ==> %d\n",ptr->data);
       ptr = ptr->front;
    }
    system("pause");
    return 0;
}
