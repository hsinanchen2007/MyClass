#include <stdio.h>

int main(void)
{
  char test = 8;
  char value = 49;

  value |= test;
  value &= (255 ^ test);

  if ((value & test) != 0)
    printf("yes.\n");
  else
    printf("no.\n");

  return 0;
}
