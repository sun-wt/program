#include "hw0101.h"

bool check_number(char *str)
{
    return (strlen(str) % 2 == 0);
}

bool check_end(char *str)
{
    return (str[strlen(str)-1] == '0' && str[strlen(str)-2] == '0');
}

bool check_string(char *str)
{
    return check_end(str) && check_number(str);  
}

bool check_value(int32_t value)
{
    return (value >= 32 && value <= 126);
}

int32_t check_kind(char target)
{
    if(number(target)) return target-48;
    else if(lower(target)) return target-97+10;
    else if(capital(target)) return target-65+10;
    else return -1;
}

int32_t reverse_bits(int32_t n) 
{
    int32_t ans = 0;
    for(int i = 0; i < sizeof(n)*2; i++)
       ans = (ans << 1) + ((n >> i) & 1); 
    return ans;
}

int32_t change_type(char first, char second)
{
    int32_t First = check_kind(first);
    int32_t Second = check_kind(second);
    if(First >= 0 && Second >= 0)
    {        
        int32_t value = reverse_bits(First*16+Second);
        if(check_value(value)) return value;
        else exit_program;
    }
    else exit_program;
}