#include <stdio.h>
#include <malloc.h>

// incoming p is a pointer to pointer
int reset(char**p, int size, int new_size)
{
    int ret = 1;
    int i = 0;
    int len = 0;
    char* pt = NULL;
    char* tmp = NULL;

    // pointer to pointer
    char* pp = *p;
    
    if( (p != NULL) && (new_size > 0) )
    {
        pt = (char*)malloc(new_size);
        
        tmp = pt;
        
        len = (size < new_size) ? size : new_size;
        
        for(i=0; i<len; i++)
        {
            // copy data from old memory to new memory
            *tmp++ = *pp++;      
        }
        
        // free old memory
        free(*p);

        // assign new memory to old memory
        *p = pt;
    }
    else
    {
        ret = 0;
    }
    
    return ret;
}

int main()
{
    char* p = (char*)malloc(5);
    
    printf("%p\n", p);
    
    // p itself is already a pointer, so if we pass &p, it is a pointer to pointer
    // then inside reset(), it will be declared as a pointer to pointer
    if( reset(&p, 5, 3) )
    {
        printf("%p\n", p);
    }

    free(p);
    
    return 0;
}
