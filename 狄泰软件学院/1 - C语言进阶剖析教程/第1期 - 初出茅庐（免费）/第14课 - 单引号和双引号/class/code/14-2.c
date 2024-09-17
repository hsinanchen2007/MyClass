#include <stdio.h>

int main()
{
    /*
        The error you're encountering, "empty character constant," is due to the line:
            char c = '';

        In C, character constants must contain exactly one character enclosed in single quotes. 
        An empty pair of single quotes is not valid.

        To fix this, you should initialize c with a valid character. If you want to initialize 
        it to a null character, you can use '\0'. Here's the corrected code:

            #include <stdio.h>

            int main()
            {
                char c = '\0';
                
                while( (c == '\t') || (c == ' ') || (c == '\n') )
                {
                    scanf("%c", &c);
                }
                
                return 0;
            }

        Explanation
        Initialization: char c = '\0'; initializes c to the null character, which is a valid 
        character constant in C.
        
        Loop Condition: The while loop checks if c is a tab ('\t'), space (' '), or newline ('\n'). 
        If any of these conditions are true, it reads another character from the input using scanf.
        Reading Input: scanf("%c", &c); reads a character from the input and stores it in c.

        Potential Issue
        The initial value of c is '\0', which is not a tab, space, or newline. Therefore, the loop 
        will not execute even once. If you want the loop to execute at least once, you might need 
        to adjust the logic. For example, you could use a do-while loop:

            #include <stdio.h>

            int main()
            {
                char c;
                
                do {
                    scanf("%c", &c);
                } while( (c == '\t') || (c == ' ') || (c == '\n') );
                
                return 0;
            }
    */

    char c = ' ';
    
    while( (c == '\t') || (c == ' ') || (c == '\n') )
    {
        scanf("%c", &c);
    }
    
    return 0;
}
