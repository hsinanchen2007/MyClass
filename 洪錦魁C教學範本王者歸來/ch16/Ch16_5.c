/*   �{���W�� : ch16_5.c                        */
/* �Q�Τ@�Ө�ƫإ��쵲��C�A�إߤ@�Ө�ƦC�L�� */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* �C�L�쵲��C��� */ 
void print_list(link pointer)
{
    while ( pointer )
    {
       printf("%d\n",pointer->data);
       pointer = pointer->next;
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
    int arr[] = { 3, 12, 8, 9, 11 };
    link  ptr;

    ptr = create_list(arr,5);
    print_list(ptr);
    system("pause");
    return 0;
}
