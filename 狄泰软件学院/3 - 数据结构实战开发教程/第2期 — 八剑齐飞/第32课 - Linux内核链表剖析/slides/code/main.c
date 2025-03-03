#include <stdio.h>
#include "LinuxList.h"

void list_demo_1()
{
    struct Node
    {
        struct list_head head;
        int value;
    };

    struct Node l = {0};
    struct list_head* list = (struct list_head*)&l;
    struct list_head* slider = NULL;
    int i = 0;

    INIT_LIST_HEAD(list);

    printf("Insert begin ...\n");

    for(i=0; i<5; i++)
    {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));

        n->value = i;

        list_add_tail((struct list_head*)n, list);
    }

    list_for_each(slider, list)
    {
        printf("%d\n", ((struct Node*)slider)->value);
    }

    printf("Insert end ...\n");

    printf("Delete begin ...\n");

    list_for_each(slider, list)
    {
        if( ((struct Node*)slider)->value == 3 )
        {
            list_del(slider);
            free(slider);
            break;
        }
    }

    list_for_each(slider, list)
    {
        printf("%d\n", ((struct Node*)slider)->value);
    }

    printf("Delete end ...\n");
}

void list_demo_2()
{
    struct Node
    {
        int value;
        struct list_head head;
    };

    struct Node l = {0};
    struct list_head* list = &l.head;
    struct list_head* slider = NULL;
    int i = 0;

    INIT_LIST_HEAD(list);

    printf("Insert begin ...\n");

    for(i=0; i<5; i++)
    {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));

        n->value = i;

        list_add(&n->head, list);
    }

    list_for_each(slider, list)
    {
        printf("%d\n", list_entry(slider, struct Node, head)->value);
    }

    printf("Insert end ...\n");


    printf("Delete begin ...\n");

    list_for_each(slider, list)
    {
        struct Node* n = list_entry(slider, struct Node, head);

        if( n->value == 3 )
        {
            list_del(slider);
            free(n);
            break;
        }
    }

    list_for_each(slider, list)
    {
        printf("%d\n", list_entry(slider, struct Node, head)->value);
    }

    printf("Delete end ...\n");
}

int main()
{
    // list_demo_1();
    // list_demo_2();

    return 0;
}
