#include <stdio.h>

int main()
{
    int arr[] = { 9, 1, 2, 1, 1, 4, 5, 5, 5, 9, 9, 9 };
    int i = 0;
    int j = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
    int n = 0;

    for(i=0; i<10; i++)
    {
        n = 0;

        for(j=0; j<len; j++)
        {
            if( i == arr[j] )
            {
                n++;
            }
        }

        printf("%d: %d\n", i, n);
    }

    return 0;
}
