#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Student
{
    char* name;
    int number;
};

char* func()
{
    char p[] = "D.T.Software";
    
    // ERROR!!! return a local variable, will cause segmentation fault 
    return p;
}

void del(char* p)
{
    printf("%s\n", p);
    
    free(p);
}

int main()
{
    struct Student s;   // s.name is not allocated memory properly
    char* p = func();
    
    // ERROR!!! s.name is not allocated memory, will cause buffer overflow
    strcpy(s.name, p); 
    
    s.number = 99;
    
    p = (char*)malloc(5);
    
    // ERROR!!! p is initialized a size 5 bytes, but copied 14 bytes, will cause buffer overflow
    strcpy(p, "D.T.Software");
    
    // ERROR!!! p is freed inside del(), but it is recommended to malloc/free in same function
    del(p);
    
    return 0;
}
