/*   程式名稱 : ch18_2.c                  */
/*   建立二元樹然後以前序 preorder 列印   */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *left, *right;
};
typedef struct list node;
typedef node *btree;
/* 建立二元樹 */
btree create_btree(btree root, int val)
{
    btree newnode, current, back;

    newnode = (btree) malloc(sizeof(node)); /*建立新節點*/ 
    newnode->data = val;                    /*存入節點值*/ 
    newnode->left = NULL;  /* 新節點左子樹指標指向 NULL */ 
    newnode->right = NULL; /* 新節點右子樹指標指向 NULL */
    if ( root == NULL )            /* 新節點是根節點    */
    {
       root = newnode;
       return root;
    }
    else                            /* 新節點是其它位置 */
    {
       current = root; /*由根節點開始找尋新節點正確位置 */ 
       while ( current != NULL )
       {
          back = current;
          if ( current->data > val )/*如果節點值大於插入值*/ 
             current = current->left;   /* 指標往左子樹走 */ 
          else
             current = current->right;  /* 指標往右子樹走 */
       }
       if ( back->data > val )  /* 如果葉節點值大於插入值 */ 
          back->left = newnode; /*新節點放在葉節點的左子樹*/ 
       else                     /* 否則 */ 
          back->right = newnode;/*新節點放在葉節點的右子樹*/
    }
    return root;
}
/* 前序列印二元樹 */ 
void preorder(btree root)
{
    if ( root != NULL )
    {
       printf("%d\n",root->data);    
       preorder(root->left);   /* 先檢查左邊子樹 */ 
       preorder(root->right);  /* 再檢查右邊子樹 */
    }
}
int main()
{
    int   arr[] = { 7, 4, 1, 5, 12, 8, 13, 11 };
    btree ptr;
    int   val, i;

    ptr = NULL;              /* 最初化根節點指標 */
    printf("使用陣列資料建立二元樹 \n");
    for ( i = 0; i < 8; i++ )
    {
       ptr = create_btree(ptr,arr[i]);
       printf("%d\n",arr[i]);
    }
    printf("使用前序preorder列印二元樹\n");
    preorder(ptr);
    system("pause");
    return 0;
}
