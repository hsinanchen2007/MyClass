#include <stdio.h>

struct TS
{
    int i;
    int j;
};

struct TS ts;

int main()
{
    short s = 0x1122;
    
    char c = (char)s;    // 0x22
    
    int i = (int)s;      // 0x00001122
    
    int j = (int)3.1415; // 3
    
    unsigned int p = (unsigned int)&ts;
    
    // long l = (long)ts;   // error
    
    // ts = (struct TS)l;   // error
    
    printf("s = %x\n", s);          // s = 1122
    printf("c = %x\n", c);          // c = 22
    printf("i = %x\n", i);          // i = 1122
    printf("j = %x\n", j);          // j = 3
    printf("p = %x\n", p);          // p = 935620
    printf("&ts = %p\n", &ts);      // &ts = 00935620
    
    return 0;
}
