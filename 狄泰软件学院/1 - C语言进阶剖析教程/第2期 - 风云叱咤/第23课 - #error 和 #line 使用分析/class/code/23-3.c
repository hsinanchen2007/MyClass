#include <stdio.h>

// The code section is written by A.
// Begin
#line 1 "a.c"

// End

// The code section is written by B.
// Begin
#line 1 "b.c"

// End

// The code section is written by Delphi.
// Begin
#line 1 "delphi_tang.c"


int main()
{
    printf("%s : %d\n", __FILE__, __LINE__);
    
    printf("%s : %d\n", __FILE__, __LINE__);
    
    return 0;
}

// End
