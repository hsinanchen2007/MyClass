#include <stdio.h>

typedef int Int32;

struct _tag_point
{
    int x;
    int y;
};

typedef struct _tag_point Point;

typedef struct
{
    int length;
    int array[];
} SoftArray; 

typedef struct _tag_list_node ListNode;
struct _tag_list_node
{
    ListNode* next;
};

int main()
{
    Int32 i = -100;        // int 
    //unsigned Int32 ii = 0;
    Point p;               // struct _tag_point
    SoftArray* sa = NULL;   
    ListNode* node = NULL; // struct _tag_list_node*
    
    return 0;
}
