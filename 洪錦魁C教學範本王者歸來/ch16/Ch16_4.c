/*   �{���W�� : ch16_4.c                  */
/*   �Ϥ�V�C�L��`��C                   */
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
    printf("�п�J 5 ����� \n");
    for ( i = 0; i <= 4; i++ )
    {
       scanf("%d",&num);
       ptr->data = num;  /* �]�w�`�I�� */
       head = ( link ) malloc(sizeof(node));
       head->next = ptr;/*�N�s���o���`�I���Ы��V�e���Ӹ`�I*/ 
       ptr = head;      /* ���] ptr ����m */ 
    }
    ptr = ptr->next;     /* �]���̫���o���`�I�S����� */
    printf("�ϧǦC�L��C \n");
    while ( ptr != NULL )  /* �p�G���O���V NULL �h�C�L */
    {
       printf("��C�� %d\n",ptr->data);
       ptr = ptr->next;
    }
    system("pause");
    return 0;
}
