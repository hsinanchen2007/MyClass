#include <stdio.h>
#include <string.h>

void right_shift_r(const char* src, char* result, unsigned int n)
{
    const unsigned int LEN = strlen(src);
    int i = 0;
        
    for(i=0; i < LEN; i++)
    {
        result[(n + i) % LEN] = src[i];
    }
    
    result[LEN] = '\0';
}

int main()
{
    char result[255] = {0};
    
    right_shift_r("abcde", result, 2);
    
    printf("%s\n", result);
    
    right_shift_r("abcde", result, 5);
    
    printf("%s\n", result);
    
    right_shift_r("abcde", result, 8);
    
    printf("%s\n", result);
    
    return 0;
}
