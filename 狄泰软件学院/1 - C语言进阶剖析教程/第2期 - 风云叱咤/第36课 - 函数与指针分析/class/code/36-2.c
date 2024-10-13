#include <stdio.h>

typedef int(*Weapon)(int);

// Weapon 並不知道要用哪個武器直到被call
void fight(Weapon wp, int arg)
{
    int result = 0;
    
    printf("Fight boss!\n");
    
    result = wp(arg);
    
    printf("Boss loss: %d\n", result);
}

int knife(int n)
{
    int ret = 0;
    int i = 0;
    
    for(i=0; i<n; i++)
    {
        printf("Knife attack: %d\n", 1);
        ret++;
    }
    
    return ret;
}

int sword(int n)
{
    int ret = 0;
    int i = 0;
    
    for(i=0; i<n; i++)
    {
        printf("Sword attack: %d\n", 5);
        ret += 5;
    }
    
    return ret;
}

int gun(int n)
{
    int ret = 0;
    int i = 0;
    
    for(i=0; i<n; i++)
    {
        printf("Gun attack: %d\n", 10);
        ret += 10;
    }
    
    return ret;
}

int main()
{
    // 回調函數, 這裡給flight()的是函數指針
    fight(knife, 3);
    fight(sword, 4);
    fight(gun, 5);
    
    return 0;
}

