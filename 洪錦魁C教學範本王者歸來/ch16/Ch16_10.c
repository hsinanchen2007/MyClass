/*   �{���W�� : ch16_10.c                 */
/*   ���V�쵲��C��������               */
#include <stdlib.h>
#include <stdio.h>
struct list           /* ���V�쵲��C�ŧi */ 
{
    int         data;
    struct list *front;  /* ���V�U���Ӹ`�I */ 
    struct list *back;   /* ���V�e���Ӹ`�I */ 
};
typedef struct list node;
typedef node *link;

int main()
{
    link  ptr,tail,head;
    int   num, i;
/* tail ���V�ģ��ӫت��`�I */ 
    tail = ( link ) malloc(sizeof(node));
    tail->back = NULL;
    tail->front = NULL;
    ptr = tail; /*�ѩ�Ĥ@���ظ`�I�ҥHptr�Mtail���V�ۦP��m*/ 
    printf("�п�J 5 ����� \n");
    for ( i = 0; i < 5; i++ )
    {
       scanf("%d",&num);
       ptr->data = num;
/* ptr ���ӱN���V�̫�ҫت��`�I */       
       head = (link) malloc(sizeof(node));
       if ( i != 4 )
       {
          head->back = ptr;
          head->front = NULL;
          ptr->front = head;
          ptr = head;   /* ptr ���V�̫�ҫت��`�I */ 
       }
    }
    printf("�ϦV�C�L���V�쵲��C\n");
    while ( ptr )
    {
       printf("��C�� ==> %d\n",ptr->data);
       ptr = ptr->back;
    }
    printf("���ǦC�L���V�쵲��C\n");
    ptr = tail;
    while ( ptr )
    {
       printf("��C�� ==> %d\n",ptr->data);
       ptr = ptr->front;
    }
    system("pause");
    return 0;
}
