/*   �{���W�� : ch18_1.c                  */
/*   �إߤG����M��H���� inorder �C�L    */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *left, *right;
};
typedef struct list node;
typedef node *btree;
/* �إߤG���� */
btree create_btree(btree root, int val)
{
    btree newnode, current, back;

    newnode = (btree) malloc(sizeof(node)); /*�إ߷s�`�I*/ 
    newnode->data = val;                    /*�s�J�`�I��*/ 
    newnode->left = NULL;  /* �s�`�I���l����Ы��V NULL */ 
    newnode->right = NULL; /* �s�`�I�k�l����Ы��V NULL */
    if ( root == NULL )            /* �s�`�I�O�ڸ`�I    */
    {
       root = newnode;
       return root;
    }
    else                            /* �s�`�I�O�䥦��m */
    {
       current = root; /*�Ѯڸ`�I�}�l��M�s�`�I���T��m */ 
       while ( current != NULL )
       {
          back = current;
          if ( current->data > val )/*�p�G�`�I�Ȥj�󴡤J��*/ 
             current = current->left;   /* ���Щ����l�� */ 
          else
             current = current->right;  /* ���Щ��k�l�� */
       }
       if ( back->data > val )  /* �p�G���`�I�Ȥj�󴡤J�� */ 
          back->left = newnode; /*�s�`�I��b���`�I�����l��*/ 
       else                     /* �_�h */ 
          back->right = newnode;/*�s�`�I��b���`�I���k�l��*/
    }
    return root;
}
/* ���ǦC�L�G���� */ 
void inorder(btree root)
{
    if ( root != NULL )
    {
       inorder(root->left);   /* ���ˬd����l�� */ 
       printf("%d\n",root->data);
       inorder(root->right);  /* �A�ˬd�k��l�� */
    }
}
int main()
{
    int   arr[] = { 7, 4, 1, 5, 12, 8, 13, 11 };
    btree ptr;
    int   val, i;

    ptr = NULL;              /* �̪�Ʈڸ`�I���� */
    printf("�ϥΰ}�C��ƫإߤG���� \n");
    for ( i = 0; i < 8; i++ )
    {
       ptr = create_btree(ptr,arr[i]);
       printf("%d\n",arr[i]);
    }
    printf("�ϥΤ���inorder�C�L�G����\n");
    inorder(ptr);
    system("pause");
    return 0;
}
