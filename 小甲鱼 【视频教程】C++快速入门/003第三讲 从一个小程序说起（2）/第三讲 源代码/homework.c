#include <stdio.h>
#include <stdlib.h>

void main()
{
      int i;
      int sum = 0;
      char ch;

      printf("������һ��������������Ŀ�Ŀո�: ");

      while( scanf("%d", &i) == 1 )
      {
            sum += i;

            while( (ch=getchar()) == ' ' )  // ���οո�
                  ;

            if( ch == '\n' ) 
            {
                  break;
            }

            ungetc( ch, stdin );  // ������ch �д�ŵ��ַ��˻ظ�stdin��������
      }
      
      printf("�����: %d", sum);
      printf("\n");
      system("pause");
}