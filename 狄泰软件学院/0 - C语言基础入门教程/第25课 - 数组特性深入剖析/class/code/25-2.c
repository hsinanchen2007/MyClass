#include <stdio.h>

int main()
{
    int arr[10] = { 0 };
    int i = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
    int x = 0;

    for(i=0; i<len; i++)
    {
        printf("Input NO.%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while( 1 )
    {
        printf("Target Number: ");
        scanf("%d", &x);

        for(i=0; i<len; i++)
        {
            if( x == arr[i] )
            {
                break;
            }
        }

        if( i < len )
        {
            printf("Index: %d\n", i + 1);
        }
        else
        {
            printf("No Target Number!\n");
        }
    }

    return 0;
}
