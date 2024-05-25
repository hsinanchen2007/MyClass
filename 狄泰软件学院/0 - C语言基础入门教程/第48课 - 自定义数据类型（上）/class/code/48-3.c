#include <stdio.h>
#include <string.h>

struct Student
{
    char name[20];
    int id;
    short major;
};

int main()
{
    struct Student s1 = {"Delphi", 908, 1};
    struct Student s2 = s1;

    printf("s1.name = %s\n", s1.name);
    printf("s1.id = %d\n", s1.id);
    printf("s1.major = %d\n", s1.major);

    strcpy(s2.name, "Tang");
    s2.id = 909;
    s2.major = 2;

    printf("s2.name = %s\n", s2.name);
    printf("s2.id = %d\n", s2.id);
    printf("s2.major = %d\n", s2.major);

    return 0;
}
