#include <stdio.h>

int getNumber(char c)
{
    int ret = -1;

    if( ('0' <= c) && (c <= '9') )
        ret = c - '0';

    return ret;
}

int str2int(char str[])
{
    int ret = 0;
    int sign = 0;
    int i = 0;

    if( getNumber(str[0]) != -1 )
    {
        sign = 1;
        i = 0;
    }
    else if( str[0] == '+' )
    {
        sign = 1;
        i = 1;
    }
    else if( str[0] == '-' )
    {
        sign = -1;
        i = 1;
    }

    while( sign && str[i] )
    {
        int n = getNumber(str[i]);

        if( n != -1 )
            ret = ret * 10 + n;
        else
            break;

        i++;
    }

    ret = sign * ret;

    return ret;
}

int main()
{
    printf("%d\n", str2int("123"));
    printf("%d\n", str2int("-12345"));
    printf("%d\n", str2int("567xyz89"));
    printf("%d\n", str2int("abc"));
    printf("%d\n", str2int("-xyz"));

    return 0;
}
