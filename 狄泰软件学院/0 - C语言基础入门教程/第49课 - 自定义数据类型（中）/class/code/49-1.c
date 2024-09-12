#include <stdio.h>
#include <string.h>

typedef  struct Student  Stu;

// we can define struct first by typedef, 
// but before using this struct, it must be defined completely
// like before main() or other API call, otherwise compiler
// cannot know the real definition and members inside the 
// struct
struct Student
{
    char name[20];
    int id;
    short major;
};

int main()
{
    Stu s;
    Stu* ps = &s;

    strcpy(ps->name, "Delphi");

    ps->id = 1;
    ps->major = 908;

    (*ps).major = 910;   // ==> s.major = 910

    printf("s.name = %s\n", s.name);
    printf("s.id = %d\n", s.id);
    printf("s.major = %d\n", s.major);

    return 0;
}
