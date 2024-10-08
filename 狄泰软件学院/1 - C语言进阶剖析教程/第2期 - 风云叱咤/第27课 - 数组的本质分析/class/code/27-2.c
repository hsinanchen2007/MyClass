#include <stdio.h>

int main()
{
    int a[5] = { 0, 1, 2, 3, 4 };

    printf("a = %p\n", a);          // a = 00AFF920
    printf("&a = %p\n", &a);        // &a = 00AFF920
    printf("&a[0] = %p\n", &a[0]);  // &a[0] = 00AFF920
    
    // a, &a, &a[0] are the same, they all point to the first element of the array
    // but *(a + 1) and *(&a + 1) are different
    printf("output 1 = %d, address %p\n", *(a + 3), (void*)(a + 3));       // output 1 = 3, address 00AFF92C

    // *(&a + 3) is a pointer arithmetic operation, it will move the pointer to 
    // the next 3 * int[5] bytes elements forward, not next 3 sizeof(int) bytes
    printf("output 2 = %d, address %p\n", *(&a + 3), (void*)(&a + 3));     // output 2 = 11532636, address 00AFF95C

    return 0;
}
