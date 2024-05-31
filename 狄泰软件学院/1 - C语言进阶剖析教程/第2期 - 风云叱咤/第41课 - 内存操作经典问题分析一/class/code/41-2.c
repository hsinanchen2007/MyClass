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
    
    return p;
}

void del(char* p)
{
    printf("%s\n", p);
    
    free(p);
}

int main()
{
    struct Student s;
    char* p = func();
    
    strcpy(s.name, p); 
    
    s.number = 99;
    
    p = (char*)malloc(5);
    
    strcpy(p, "D.T.Software");
    
    del(p);
    
    return 0;
}
