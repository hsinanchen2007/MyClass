/*   �{���W�� : ch4_29.c                  */
/*   �Y�ɿ��]�p                         */
int main()
{
    int i;
    printf("\1: 1. Access    ......  \n");
    printf("\1: 2. Excel     ......  \n");
    printf("\1: 3. Word      ......  \n");
    printf("�п�� ==> ");
    scanf("%d",&i);
    printf("\n");
    switch ( i )
    {
       case 1: printf("Access �O��Ʈw�n�� \n");
	       break;
       case 2: printf("Excel �O�պ��n�� \n");
	       break;
       case 3: printf("Word ��ѳB�z�n�� \n");
	       break;
       default:
	       printf("�S����� \n");
    }
    system("pause");
    return 0;
}
