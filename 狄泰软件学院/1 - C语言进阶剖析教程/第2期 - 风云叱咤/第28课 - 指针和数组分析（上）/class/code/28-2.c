#include <stdio.h>

int main()
{
    char s1[] = {'H', 'e', 'l', 'l', 'o'};
    int i = 0;
    char s2[] = {'W', 'o', 'r', 'l', 'd'};
    char* p0 = s1;
    char* p1 = &s1[3];
    char* p2 = s2;
    int* p = &i;
	
    printf("%d\n", p0 - p1);    // -3
    // printf("%d\n", p0 + p2); // error, invalid operands to binary +
    // printf("%d\n", p0 - p2); // error, invalid operands to binary -
    // printf("%d\n", p0 - p);  // error, invalid operands to binary -
    // printf("%d\n", p0 * p2); // error, invalid operands to binary *
    // printf("%d\n", p0 / p2); // error, invalid operands to binary /
	
    return 0;
}
