#include "mystring.h"

int change(int c)
{
    return (int)isalpha(c) ? (c-'a' >= 0 ? c-'a'+10 : c-'A'+10) : (c > '9' || c < '0' ? 37 : c-'0');
}

long int mystrtol(const char *nptr, char **endptr , int base)
{
    int32_t size = 0; long ans = 0; bool sign = 0;
    if(base < 0 || base >= 36) return 0;
    while(*nptr == ' ') nptr++;
    if(*nptr == '-') {nptr++; sign = 1;}
    if(base == 0)
    {
        if(strncmp(nptr, "0x", 2) == 0) nptr += 2;
        base = 16;
    }
    while(change(nptr[size]) < base && nptr[size] != '\0') 
        size++;
    for(int i = 0; i < size; i++) ans += change(nptr[i])* pow(base, size-i-1);
    ans *= pow(-1, sign);
    while(size != 0) {nptr++; size--;}
    if(endptr != NULL) *endptr = (char*)nptr;
    return ans;
}
