#include "mystring.h"

int main ()
{
    char szNumbers[] = " 2001 60C0c0 -11011101001101001 0x6ffff";
    char * pEnd;
    long int li1, li2, li3, li4;
    li1 = mystrtol(szNumbers,&pEnd,10);
    li2 = strtol(pEnd,&pEnd,16);
    li3 = strtol(pEnd,&pEnd,2);
    li4 = strtol(pEnd,NULL,0);
    printf ("10進制: %ld、%ld、%ld、%ld\n", li1, li2, li3, li4);
    return 0;
}