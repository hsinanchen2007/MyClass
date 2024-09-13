#include <stdio.h>

int main()
{
 
    unsigned int i = 5;
    int j = -10;
    
    // when signed and unsigned values are calculated,
    // compiler will make signed value becomes unsigned value
    // first then count it. To show its value, should use "%u"
    if( (i + j) > 0 )
    {
        printf("i + j > 0, i + j = %u\n", i + j);   // i + j > 0, i + j = 4294967291
        printf("unsigned i = %u\n", i);             // unsigned i = 5
        printf("unsigned j = %u\n", j);             // unsigned j = 4294967286
        printf("signed i = %d\n", i);               // signed i = 5
        printf("signed j = %d\n", j);               // signed j = -10
    }
    else
    {
        printf("i + j <= 0\n");
    }
    
    return 0;
}
