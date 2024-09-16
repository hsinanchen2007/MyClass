#include <stdio.h>

// re-define existing type
typedef int Int32;

// define a new type based on existing type
struct _tag_point
{
    int x;
    int y;
};
typedef struct _tag_point Point;

// define a new type after struct definition
typedef struct
{
    int length;
    int array[];
} SoftArray; 

// define a new type first and then use it in struct definition
typedef struct _tag_list_node ListNode;
struct _tag_list_node
{
    ListNode* next;
};

int main()
{
    Int32 i = -100;        // int 

    // new defined type cannot be used with unsigned or signed
    //unsigned Int32 ii = 0;

    Point p;               // struct _tag_point
    SoftArray* sa = NULL;   
    ListNode* node = NULL; // struct _tag_list_node*
    
    return 0;
}
