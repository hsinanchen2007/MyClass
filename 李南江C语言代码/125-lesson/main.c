#include <stdio.h>

int main()
{
    /*
     * 1.字符串的存储细节
     * 和数组一样
     */
    char str1[] = {'l','n','j','\0'};

//    int len = sizeof(str1) / sizeof(str1[0]);
//    for(int i = 0; i < len; i++){
//        printf("%c", str1[i]);
//    }

//    int index = 0;
//    while(str1[index] != '\0'){
//        printf("%c", str1[index]);
//        index++;
//    }

    printf("str1 = %s\n", str1); // lnj

//    char str2[] = "lnj";
//    printf("str2 = %s\n", str2);

    char str2[] = {'l','n','j'};
    printf("str2 = %s\n", str2);
    return 0;
}
