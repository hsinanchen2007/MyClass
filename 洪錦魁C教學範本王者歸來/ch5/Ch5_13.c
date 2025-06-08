01  /*   程式名稱 : ch5_13.c                  */
02  /*   4 * 4 魔術方塊                       */
03  #include <stdio.h>
04  #include <stdlib.h>
05  int main()
06  {
07      int magic[4][4];
08      int first;        /* 起始值       */
09      int step;         /* 差值         */
10      int sum;          /* 最小值與最大值之和    */
11      int tmp;
12      int i,j;
13  
14      printf("輸入 4 * 4 魔術方塊起始值 \n");
15      printf("  ===> ");
16      scanf("%d",&first);
17      printf("輸入差值 \n  ==> ");
18      scanf("%d",&step);
19      tmp = first;
20      for ( i = 0; i < 4; i++ )
21         for ( j = 0; j < 4; j++ )
22         {
23            *(*(magic+i)+j) = tmp;
24            tmp += step;
25         }
26      printf("起初的魔術方塊如下 \n");
27      for ( i = 0; i < 4; i++ )
28      {
29         for ( j = 0; j < 4; j++ )
30            printf("%5d",*(*(magic+i)+j));
31         printf("\n");
32      }
33      sum = **magic + *(*(magic+3)+3);
34      for ( i = 0, j = 0; i < 4; i++, j++ )
35         *(*(magic+i)+j) = sum - *(*(magic+i)+j);
36      for ( i = 0, j = 3; i < 4; i++, j-- )
37         *(*(magic+i)+j) = sum - *(*(magic+i)+j);
38      printf("最後的魔術方塊如下 \n");
39      for ( i = 0; i < 4; i++ )
40      {
41         for ( j = 0; j < 4; j++ )
42            printf("%5d",*(*(magic+i)+j));
43         printf("\n");
44      }
45      system("pause");
46      return 0;        
47  }