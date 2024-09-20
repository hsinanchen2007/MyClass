
#define ERROR -1
#define PATH1 "D:\test\test.c"

// macro definition with multi-line will require '\' at the end of each line
// and the last line should not have '\'. Also, the macro definition should contain "" for a string
// #define PATH2 D:\test\test.c
// #define PATH3 D:\test\
// test.c

int main()
{
    int err = ERROR;
    char* p1 = PATH1;
    // char* p2 = PATH2;
    // char* p3 = PATH3;
}
