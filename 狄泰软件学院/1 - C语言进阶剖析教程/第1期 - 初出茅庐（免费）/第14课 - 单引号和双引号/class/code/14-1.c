#include <stdio.h>

int main()
{

    char* p1 =  1 ; // warning: initialization makes pointer from integer without a cast, and point to a low memory address
    char* p2 = '1'; // warning: initialization makes pointer from integer without a cast, and point to a low memory address
    char* p3 = "1"; // OK

    // below will fail to print the values of p1 and p2  
    printf("%s, %s, %s", p1, p2, p3);
    
    printf('\n');
    printf("\n");
    
    return 0;
}
