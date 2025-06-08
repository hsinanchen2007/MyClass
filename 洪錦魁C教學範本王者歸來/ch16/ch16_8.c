/*   �{���W�� : ch16_8.c                  */
/*   �Ѥp��j�C�X�쵲��C��               */
/*   ���{���b�R���`�I�ɼW�[ free() �ʧ@   */ 
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* �R���쵲��C�����I */ 
link delete_node(link pointer, link tmp)
{
    link deletenode;
    
    if ( tmp == NULL )                /* �R���Ĥ@�Ӹ`�I   */
    {
       tmp = pointer->next;
       free(pointer);
       return tmp;
    }   
    else
    {
       if ( tmp->next->next == NULL ) /* �R���̫᣸�Ӹ`�I */
       {
          deletenode = tmp->next;
          tmp->next = NULL;
          free(deletenode);
       }   
       else                           /* �R���䥦�`�I     */
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
       btmp = NULL; /* �Ȯɳ]�w���ӱN���V�̤p�ȸ`�I */ 
       while ( tmp->next )
       {
          if ( min > tmp->next->data )
          {
             min = tmp->next->data;
             btmp = tmp;     /* ���V�̤p�ȸ`�I */
          }
          tmp = tmp->next;
       }
       printf("%d\n",min);   /* �C�L�̤p�� */ 
       pointer = delete_node(pointer,btmp);
    }
}
/* �N�}�C�ন�쵲��C��� */
link create_list(int array[],int num)
{
    link tmp1,tmp2,pointer;
    int  i;
/* pointer ���V��C���Ĥ@�Ӹ`�I */ 
    pointer = ( link ) malloc(sizeof(node));
    pointer->data = array[0]; /* �Ĥ@�����   */ 
    tmp1 = pointer;           /* ���ʼȮɫ��� */ 
    for ( i = 1; i < num; i++ )
    {
       tmp2 = (link) malloc(sizeof(node));
       tmp2->next = NULL;
       tmp2->data = array[i];
       tmp1->next = tmp2;     /* �¸`�I���Ы��V�s�`�I */ 
       tmp1 = tmp1->next;     /* ���ʼȮɫ��� */
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
