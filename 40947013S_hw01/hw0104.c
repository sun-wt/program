#include "mystring.h"

int main() 
{
    int32_t choose = 0;
    printf( "%s\n" , mystrchr("ppppppppuuuuuuiuiuiuiu", 'i' ) );
    printf( "%s\n" , mystrrchr("ppppppppuuuuuuiuiuiuiu", 'i' ) );
    printf( "%zu\n" , mystrspn("ABCDEFG12345", "ABCDEFGFRW") );
    printf( "%zu\n" , mystrcspn("ABCDEFG", "ABCFRW") );
    printf( "%s\n" , mystrpbrk("abcde2fghi3jk4l","34") );

    printf( "%s\n" , mystrstr("pls tell me", "tell" ) );
    char str[128] = "to be or not to be";
    char *token = mystrtok(str, "to");
    while(token)
    {
        printf("%s\n", token);
        token = mystrtok(NULL, "to");
    }
}