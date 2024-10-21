#include <stdio.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE*)0)->MEMBER)
#endif


struct ST
{
    int i;     // 0
    int j;     // 4
    char c;    // 8
};

void func(struct ST* pst)
{
    int* pi = &(pst->i);    //  0
    int* pj = &(pst->j);    //  4
    char* pc = &(pst->c);   //  8

    printf("pst = %p\n", pst);
    printf("pi = %p\n", pi);
    printf("pj = %p\n", pj);
    printf("pc = %p\n", pc);
}

int main()
{
    struct ST s = {0};

    func(&s);
    func(NULL);

    printf("offset i: %d\n", offsetof(struct ST, i));
    printf("offset j: %d\n", offsetof(struct ST, j));
    printf("offset c: %d\n", offsetof(struct ST, c));

    return 0;
}
