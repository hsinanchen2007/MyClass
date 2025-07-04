/* struct */
#include <stdio.h>
struct date {
  int year;
  int month;
  int day;
};
typedef struct date Date;

#define NAMELEN 20
#define PHONELEN 10
#define YEAR 4
struct student {
  char name[NAMELEN];
  int id;
  char phone[PHONELEN];
  float grade[YEAR];
  Date birthday;
};
typedef struct student Student;
/* main */
int main(void)
{
  Student john = 
    {"John Smith", 12345, "1234567", 
     {4.0, 3.9, 3.8, 3.6}, {2000, 1, 1}};
  printf("name is %s\n", john.name);
  printf("id is %d\n", john.id);
  printf("phone is %s\n", john.phone);
  printf("grade is %f %f %f %f\n", 
	 john.grade[0], john.grade[1],
	 john.grade[2], john.grade[3]);
  printf("birth year is %d\n", 
	 john.birthday.year);
  printf("birth month is %d\n", 
	 john.birthday.month);
  printf("birth day is %d\n", 
	 john.birthday.day);
  return 0;
}
/* end */
