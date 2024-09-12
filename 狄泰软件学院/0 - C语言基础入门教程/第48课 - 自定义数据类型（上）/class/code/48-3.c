#include <stdio.h>
#include <string.h>

struct Student
{
    char name[20];
    int id;
    short major;
};

// by using typedef, can define another name of this struct
typedef struct Student2 
{
    char name[20];
    int id;
    short major;
} STUDENT2;

// without typedef, the name after } can be only same as its struct name
struct Student3 
{
    char name[20];
    int id;
    short major;
} Student3;

int main()
{
    struct Student s1 = {"Delphi", 908, 1};
    struct Student s2 = s1;

    // test typedef's new name
    STUDENT2 s3 = {"Delphi", 908, 1};

    // test original struct name
    struct Student2 s4 = {"Delphi", 908, 1};

    // no typedef, can be only same struct name
    struct Student3 s5 = {"Delphi", 908, 1};

    printf("s1.name = %s\n", s1.name);          // s1.name = Delphi
    printf("s1.id = %d\n", s1.id);              // s1.id = 908
    printf("s1.major = %d\n", s1.major);        // s1.major = 1

    strcpy(s2.name, "Tang");
    s2.id = 909;
    s2.major = 2;

    printf("s2.name = %s\n", s2.name);          // s2.name = Tang
    printf("s2.id = %d\n", s2.id);              // s2.id = 909
    printf("s2.major = %d\n", s2.major);        // s2.major = 2

    return 0;
}
