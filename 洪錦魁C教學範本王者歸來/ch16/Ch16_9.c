/*   �{���W�� : ch16_9.c                  */
/*   ���w�j�ƧǦA���洡�J�`�I             */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* �N�`�I���b�ƧǦ�C�� */ 
link insert_node(link pointer, link tmp, int value)
{
    link newnode;
    if ( tmp == NULL )  /* �s���I���b�ģ��Ӹ`�I�e�� */
    {
       newnode = (link) malloc(sizeof(node));
       newnode->data = value;   /* �]�w�s���I�� */ 
       newnode->next = pointer; /* �s���I���Ы��V��C�ģ��Ӹ`�I*/ 
       return newnode;
    }
    else
    {
       if ( tmp->next == NULL ) 
       {       /* �s���I���b�̫᣸�Ӹ`�I�᭱ */ 
          newnode = (link) malloc(sizeof(node));
          newnode->data = value; /* �]�w�s���I�� */
          tmp->next = newnode; /*��C�̫᣸�Ӹ`�I���Ы��V�s���I*/ 
          newnode->next = NULL;
       }
       else    /* �s���I���b�쵲��Ctmp���Ы᭱ */
       {
          newnode = (link) malloc(sizeof(node));
          newnode->data = value; /* �]�w�s���I�� */
          newnode->next = tmp->next;
          tmp->next = newnode; /* tmp���Ы��V�s���I */ 
       }
       return pointer;
    }
}
/* �j�M���J��C����m */ 
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
          OTRUE = 0;  /* �������J���I�ߨ����}�j�� */ 
       if ( OTRUE )
       {
          btmp = tmp;
          tmp = tmp->next;
       }
    }
    /* �p�G btmp �O NULL �h�O���A��C�Ĥ@�Ӹ`�I�e�� */
    /* �_�h���b btmp �ҫ��`�I���U���Ӧ�m           */ 
    pointer = insert_node(pointer,btmp,value);
    return pointer;
}
/* �N��`��C�Ѥp�ƨ�j */ 
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
          {  /* �p�G�e�����j��U�����h��ո`�I�� */ 
             value = tmp->data;
             tmp->data = tmp->next->data;
             tmp->next->data = value;
          }
          tmp = tmp->next; /* ���ʼȮɫ��ЦܤU���`�I */ 
       }
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
/* �C�L�쵲��C��� */
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
    printf("���J�`�I�e������C�L \n");
    print_list(ptr);
    ptr = search_insert_location(ptr,15);
    printf("���J�`�I 15 �A�C�L \n");
    print_list(ptr);
    ptr = search_insert_location(ptr,7);
    printf("���J�`�I 7  �A�C�L \n");
    print_list(ptr);
    system("pause");
    return 0;
}
