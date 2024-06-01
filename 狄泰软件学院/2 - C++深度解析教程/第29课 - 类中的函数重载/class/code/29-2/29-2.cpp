#include <stdio.h>
#include <string.h>

// Need to add this _CRT_SECURE_NO_WARNINGS to compile it in VC 2022
// Under "Project -> Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions" 
// then add _CRT_SECURE_NO_WARNINGS
// Note that C didn't support overload, here we add one more argument
// with same function name, so it will call real C library function
// within this function
char* strcpy(char* buf, const char* str, unsigned int n)
{
    return strncpy(buf, str, n);
}

int main()
{
    const char* s = "D.T.Software";
    char buf[8] = { 0 };

    // strcpy(buf, s);
    strcpy(buf, s, sizeof(buf) - 1);

    printf("%s\n", buf);

    return 0;
}
