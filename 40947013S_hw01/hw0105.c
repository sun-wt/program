#include "mysplit.h"

int main()
{
	char *buf="1,2,3,4,444,41";
	char **return_list; char *s = ",";

	int size = 0;
 
    mystrsplit(&return_list, &size, buf, s);
    for(int i = 0; i < size; i++)
        if(return_list[i] != 0)printf("%s\n", return_list[i]);
    return 0;
}