#include <stdio.h>

#define DIM(a) (sizeof(a) / sizeof(*a))

int main()
{
    char s[] = {'H', 'e', 'l', 'l', 'o'};
    char* pBegin = s;
    char* pEnd = s + DIM(s); // Key point
    char* p = NULL;
    
    printf("pBegin = %p\n", pBegin);
    printf("pEnd = %p\n", pEnd);
    
    printf("Size: %d\n", pEnd - pBegin);
	
    for(p=pBegin; p<pEnd; p++)
    {
        printf("%c", *p);
    }
    
    printf("\n");
   
    return 0;
}
