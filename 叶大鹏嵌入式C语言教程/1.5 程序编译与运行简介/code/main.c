#include <stdio.h>
#include "ARMCM4.h"   

struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;
 
int fputc(int ch, FILE *f) 
{
    return ITM_SendChar(ch);
}

volatile int32_t ITM_RxBuffer;
int fgetc(FILE *f) 
{
    while(ITM_CheckChar() != 1)
	      __NOP();
    return (ITM_ReceiveChar());
}
int ferror(FILE *f) 
{
  /* Your implementation of ferror */
  return EOF;
}

void _ttywrch(int ch) 
{
//  sendchar (ch);
	fputc(ch, &__stdout);
}

int __backspace()
{
	return 0;
}
void _sys_exit(int return_code) 
{
  while (1);    /* endless loop */
}

typedef struct
{
    char id;
    char age; 
    char name[10];
		char sex[10];
		int  height;		
} STUDENT;

typedef struct
{
	  char name[10];
    STUDENT students[50];
    int num;
} CLASS;

void add_student(CLASS *cla, STUDENT stu)
{
    cla->students[cla->num] = stu;
    (cla->num)++;
}
int main(void)//’‚ «◊¢ Õ
{
	  printf("STUDENT size is %d\n", sizeof(STUDENT));
    volatile CLASS class1 = {
        "class 1",
		    {{1, 9, "zhangsan", "male", 130},
				 {2, 10, "lisi",   "female"}, 135},
				2
		};

		volatile STUDENT stu = {3, 9, "wangwu", "male"};
    add_student(&class1, stu);
    for (int i = 0; i < class1.num; i++)
		{
        printf("%d 's name is %s\n", i, class1.students[i].name);
		}
		return 0;
}
