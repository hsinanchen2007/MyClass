#include <stdio.h>
#include <string.h>

#define DIM(a) (sizeof(a)/sizeof(*a))

// same as "const char **table", but not good for readability
int lookup_keyword(const char* key, const char* table[], const int size) 
{
    int ret = -1;
    
    int i = 0;
    
    for(i=0; i<size; i++)
    {
        if( strcmp(key, table[i]) == 0 )
        {
            ret = i;
            break;
        }
    }
    
    return ret;
}

int main()
{
    // keyword就是指針數組, 每個元素都是指向字符串的指針
    const char* keyword[] = {
            "do",
            "for",
            "if",
            "register",
            "return",
            "switch",
            "while",
            "case",
            "static"
    };
    
    printf("%d\n", lookup_keyword("return", keyword, DIM(keyword)));    // 4
    printf("%d\n", lookup_keyword("main", keyword, DIM(keyword)));      // -1

    return 0;
}

