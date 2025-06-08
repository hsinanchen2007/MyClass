/*   程式名稱 : ch2_2.c                   */
/*   認識所使用編譯程式對變數長度的設定   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    printf("int = %d\n", sizeof(int));
    printf("short int = %d\n", sizeof(short int));
    printf("long int = %d\n", sizeof(long int));
    printf("float = %d\n", sizeof(float));
    printf("double = %d\n", sizeof(double));
    printf("char = %d\n", sizeof(char));
    system("pause");
    return 0;
}
