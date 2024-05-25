#include <stdio.h>

int main()
{
    int arr[] = { 9, 1, 2, 1, 1, 4, 5, 5, 5, 9, 9, 9 };
    int i = 0;
    int j = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
    int cnt[10] = {0};
    int num = 0;

    for(j=0; j<len; j++)
    {
        num = arr[j];
        cnt[num] += 1;
    }

    for(i=0; i<10; i++)
    {
        printf("%d. %d\n", i, cnt[i]);
    }

    return 0;
}
