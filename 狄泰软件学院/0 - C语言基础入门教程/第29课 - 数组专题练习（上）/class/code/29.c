#include <stdio.h>

#define LN  50
#define SN  10

int main()
{
    int light[LN] = {0};
    int student[SN] = {0};
    int i = 0;
    int j = 0;

    for(i=0; i<LN; i++)  light[i] = 1;  // 1 表示灯的打开状态， 0 表示灯的关闭状态

    for(i=0; i<SN; i++)  student[i] = (i + 1) * 2;  // 2, 4, 6, 8, ...

    for(i=0; i<SN; i++)
        for(j=0; j<LN; j++)
            if( (j + 1) % student[i] == 0 )
            {
                light[j] = !light[j];
            }

    for(i=0; i<LN; i++)
        if( light[i] )
            printf("%d ", i + 1);

    return 0;
}
