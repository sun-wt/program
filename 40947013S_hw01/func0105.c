#include "mysplit.h"

int mystrsplit(char **ppList , int *pCounter , const char *pStr, const char *
pSeparator)
{
    if(pStr == NULL) return -1;
    char *copy = malloc(strlen(pStr)+1);
    strncpy(copy, pStr, strlen(pStr));
    if(pSeparator == NULL || strlen(pSeparator) == 0)
    {
        char *token = strtok(copy, " ");
        while(token != NULL)
        {
            *ppList++ = token;
            (*pCounter)++;
            token = strtok(NULL, " ");
        }
        return 0;
    }
    if(strstr(copy, pSeparator) == NULL) 
    {
        *ppList = pStr; *pCounter = 1; return 0;
    }

    int table[100]; table[0] = strlen(pStr)-strlen(pSeparator)+1;
    int length[100];
    do{
        char *replace = malloc(strlen(pStr)+1);
        strcpy(replace, strstr(copy, pSeparator));
        replace += strlen(pSeparator);
        strcpy(copy, replace);
        table[(*pCounter)+1] = strlen(copy); (*pCounter)++;
    }while(strstr(copy, pSeparator) != NULL);
    (*pCounter)++; *ppList = malloc(*pCounter);
    for(int i = 0; i < (*pCounter); i++)
    {
        int start = i == 0 ? 0 : strlen(pStr)-table[i];
        int end = (i != (*pCounter)-1) ? strlen(pStr)-table[i+1]-strlen(pSeparator) : strlen(pStr);
        length[i] = end - start;
        if(length[i] == 0) {ppList[i] = NULL; continue;}
        ppList[i] = malloc(strlen(pStr));
        int32_t count = 0;
        for(int j = start; j < end; j++)
            ppList[i][count++] = pStr[j];
        ppList[i][count] = '\0';
    }
    return *pCounter == 1 ? -1 : 0;
}