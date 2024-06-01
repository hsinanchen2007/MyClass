#include <stdio.h>

float average(int array[], int size)
{
    int i = 0;
    float avr = 0;
    
    for(i=0; i<size; i++)
    {
        avr += array[i];
    }
    
    return avr / size;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    
    printf("%f\n", average(array, 5));
    
    return 0;
}

