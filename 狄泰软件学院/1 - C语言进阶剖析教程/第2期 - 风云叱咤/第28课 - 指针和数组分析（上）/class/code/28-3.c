#include <stdio.h>

// sizeof(a) / sizeof(*a) is a common way to get the number of elements in an array 
#define DIM(a) (sizeof(a) / sizeof(*a))

int main()
{
    char s[] = {'H', 'e', 'l', 'l', 'o'};
    char* pBegin = s;
    char* pEnd = s + DIM(s); // Key point
    char* p = NULL;
    
    printf("pBegin = %p\n", pBegin);        // pBegin = 00C2FC28
    printf("pEnd = %p\n", pEnd);            // pEnd = 00C2FC2D
    
    printf("Size: %d\n", pEnd - pBegin);    // Size: 5
	
    for(p=pBegin; p<pEnd; p++)
    {
        printf("%c", *p);   // Hello
    }
    
    printf("\n");
   
    return 0;
}
