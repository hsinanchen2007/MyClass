#include <stdio.h>

#define STRUCT(type) typedef struct _tag_##type type;\
                     struct _tag_##type

STRUCT(Student)
{
    char* name;
    int id;
};

int main()
{
    
    Student s1;
    Student s2;
    
    s1.name = "s1";
    s1.id = 0;
    
    s2.name = "s2";
    s2.id = 1;
    
    printf("s1.name = %s\n", s1.name);  // s1.name = s1
    printf("s1.id = %d\n", s1.id);      // s1.id = 0
    printf("s2.name = %s\n", s2.name);  // s2.name = s2
    printf("s2.id = %d\n", s2.id);      // s2.id = 1

    return 0;
}
