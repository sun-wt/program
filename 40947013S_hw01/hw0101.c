#include "hw0101.h"

int main() 
{
    char *input = calloc(1024, sizeof(int));
    printf("Please enter the hex string: ");
    fgets(input, 1024, stdin);
    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = 0;
    if(check_string(input) == false) exit_program;
    for(int i = 0;i < (strlen(input)/2)-1; i++)
    {    
        printf("%c", change_type(input[i*2], input[i*2+1]));
    }
    printf("\n");
    return 0;
}