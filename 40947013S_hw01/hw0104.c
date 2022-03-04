#include "mystring.h"

int main()
{
    printf("%s\n", mystrchr("ppppppppuuuuuuiuiuiuiu", 'i'));
    printf("%s\n", mystrrchr("ppppppppuuuuuuiuiuiuiu", 'i'));
    printf("%zu\n", mystrspn("ABCD1234", "ABC"));
    printf("%zu\n", mystrcspn("ABCDEFG1234", "1234"));
    printf("%s\n", mystrpbrk("abcde2fghi3jk4l", "43"));
    printf("%s\n", mystrstr("ppppppppuuuuuuiuiuiuiu", "iu"));
    char str[80] = "This is - www.gitbook.net - website";
    char s[2] = "-";
    char *token = mystrtok(str, s);
    while( token != NULL ) 
    {
        printf( "%s\n", token );
        token = mystrtok(NULL, s);
    }  
    return 0;
}