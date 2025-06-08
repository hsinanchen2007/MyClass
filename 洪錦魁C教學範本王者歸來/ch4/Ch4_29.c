/*   程式名稱 : ch4_29.c                  */
/*   即時選單設計                         */
int main()
{
    int i;
    printf("\1: 1. Access    ......  \n");
    printf("\1: 2. Excel     ......  \n");
    printf("\1: 3. Word      ......  \n");
    printf("請選擇 ==> ");
    scanf("%d",&i);
    printf("\n");
    switch ( i )
    {
       case 1: printf("Access 是資料庫軟體 \n");
	       break;
       case 2: printf("Excel 是試算表軟體 \n");
	       break;
       case 3: printf("Word 文書處理軟體 \n");
	       break;
       default:
	       printf("沒有選擇 \n");
    }
    system("pause");
    return 0;
}
