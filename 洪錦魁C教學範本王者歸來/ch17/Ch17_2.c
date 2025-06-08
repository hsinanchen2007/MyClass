/*   �{���W�� : ch17_2.c                  */
/*   enqueue �M dequeue ��ƪ�����        */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int         data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
/* �N��Ʀs�J��C */ 
link enqueue(link queue, int value)
{
    link  newnode;

    newnode = (link) malloc(sizeof(node));
    newnode->data = value;  /* �N��Ʀs�J�s�ئ�C�`�I    */ 
    newnode->next = NULL;
    if ( queue != NULL )    /* ����queue(ptrb)���V�s���I */
    {
       queue->next = newnode;
       queue = queue->next;
    }
    else
       queue = newnode;     /* �زģ��Ӹ`�I���]�w        */
    return queue;
}
/* Ū����C��� */ 
link dequeue(link queue, int *value)
{
    link  dequeuenode;

    dequeuenode = queue;
    *value = dequeuenode->data;  /* ���o��C��� */ 
    queue = queue->next; /* ���s�]�wqueue(ptrf)���Ц�m */ 
    free(dequeuenode);   /* ���o��ƫ�Y���^�O�ЪŶ�    */ 
    return queue;
}
int main()
{
    int   arr[] = { 3, 12, 8, 9, 11 };
    link  ptrb, ptrf;
    int   val, i;

    ptrf = NULL;    /* �̪�Ʀ�C�_�l�`�I���� */
    ptrb = ptrf;    /* �̪�Ʀ�C���ݸ`�I���� */
    printf("�ϥ� enqueue �إߦ�C \n");
    for ( i = 0; i < 5; i++ )
    {
       ptrb = enqueue(ptrb,arr[i]);
       if ( ptrf == NULL )     /* ���ߥN��زģ��Ӧ�C�`�I */ 
          ptrf = ptrb; /*�زģ��Ӹ`�I�ɨ�ӫ��Ы��V�ۦP��m*/ 
       printf("%d\n",arr[i]);
    }
    printf("�ϥ� dequeue �C�L��C \n");
    for ( i = 0; i < 5; i++ )
    {
       ptrf = dequeue(ptrf,&val);
       printf("%d\n",val);
    }
    system("pause");
    return 0;
}
