#include "hw0102.h"

void cut_end(char *input)
{
    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = 0;
}

bool punctuation_marks(char *token, char *target)
{
    int32_t size = strlen(target);
    if(strlen(token) == size+1 && strncmp(token, target, size) == 0)
        if(token[size] == '?' || token[size] == '.' || token[size] == '!' || token[size] == ',' || token[size] == ':')
            return true;
    return false;
}

bool check_keyword(char *table, char *target)
{
    bool used = 0;
    char *copy_table = calloc(strlen(table), sizeof(int));
    strncpy(copy_table, table, strlen(table));
    char *token = strtok(copy_table, " ");
    while(token)
    {
        if(strcmp(token, target) == 0 || punctuation_marks(token, target))
        {
            used = 1; break;
        }
        token = strtok(NULL, " ");
    }
    if(used) return true;
    else exit_program;
}

void replace(char *table, char *target, char *replace, bool flag)
{
    char *copy_table = calloc(strlen(table), sizeof(int));
    strncpy(copy_table, table, strlen(table));
    char *token = strtok(copy_table, " ");
    while(token)
    {
        if(strcmp(token, target) == 0)
        {
            if(flag) printf(RED"%s "RESET, replace);
            else printf(RED"%s "RESET, target);
        }
        else 
        {
            if(punctuation_marks(token, target) )
            {
                if(flag) printf(RED"%s"RESET, replace);
                else printf(RED"%s"RESET, target);   
                printf("%c ", token[strlen(token)-1]);
            }
            else printf("%s ", token);  
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}