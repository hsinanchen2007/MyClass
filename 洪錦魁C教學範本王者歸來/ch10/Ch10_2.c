/*   �{���W�� : ch10_2.c                  */
/*   ²���r�����                         */
#include <stdio.h>
#include <stdlib.h>
void string_copy(char s1[], char s2[], int num)
{
    int j;
    for ( j = 0; j < num; j++ )
        s2[j] = s1[j];  /* �N s1 �r�ꤺ�e��� s2 */ 
}        
int main()
{
    char str1[5] = {'B','o','o','k','s'};
    char str2[5];
    int  i;

    string_copy(str1,str2,5);
    for ( i = 0; i < 5; i++ )  /* �C�L�r�� */ 
        printf("%c",str2[i]);
    printf("\n");
    system("pause");
    return 0;
}












































































































































































































