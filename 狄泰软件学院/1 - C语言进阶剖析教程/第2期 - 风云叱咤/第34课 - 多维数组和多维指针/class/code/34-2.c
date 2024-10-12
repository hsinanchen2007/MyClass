#include <stdio.h>
#include <malloc.h>

void printArray(int a[], int size)
{
    int i = 0;
    
    printf("printArray: %d\n", sizeof(a));

    // array inside computer is still one dimension array
    for(i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }
}

int main()
{
    int a[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int* p = &a[0][0];
    
    int i = 0;
    int j = 0;
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d, ", *(*(a+i) + j));  // 就是 *(a + 1) ==> a[i], *(a[i] + j) ==> a[i][j]
        }
        
        printf("\n");
    }
    
    printf("\n");
    
    printArray(p, 9);
    
    return 0;
}
