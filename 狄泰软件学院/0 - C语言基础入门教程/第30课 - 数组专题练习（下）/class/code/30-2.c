#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "abc\0de\0fg";
    int size = sizeof(s);
    int i = 0;
    int j = 0;

    while( i < size )
    {
        if( s[i] == 0 )
        {
            for(j=i+1; j<size; j++)
            {
                s[j-1] = s[j];
            }

            size--;
        }
        else
        {
            i++;
        }
    }

    printf("s = %s\n", s);

    return 0;
}
