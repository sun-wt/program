#include "mysplit.h"

int main()
{
    char *return_list[8] = {0}; int size = 0; 
    mystrsplit(return_list, &size, "1,2,3,1,2,3", "1,2,3 1,2,3");
    printf("%d\n", size);
    for(int i = 0; i < size; i++)
        if(return_list[i] != 0) printf("%s\n", return_list[i]);
    return 0;
}