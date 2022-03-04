#include "mystring.h"

char *mystrchr(const char *s, int c)
{
    while(*s != '\0')
        if(*s == c) return (char*)s;
        else s++;
    return NULL;
}

char *mystrrchr(const char *s, int c)
{
    while(*s != '\0') s++;
    while(s != 0)
        if(*s == c) return (char*)s;
        else s--;
    return NULL;
}

size_t mystrspn(const char *s, const char *accept)
{
    size_t size = 0, last = size;
    while(*s != '\0')
    {
        for(int i = 0; i < strlen(accept); i++)
        {
            if(*s == accept[i])
                size++;
        }
        if(last == size) break;
        last = size; s++; 
    }
    return size;
}

size_t mystrcspn(const char *s, const char *reject)
{
    size_t size = 0;
    while(*s != '\0')
    {
        for(int i = 0; i < strlen(reject); i++)
        {
            if(*s == reject[i]) return size;
        }
        s++; size++;
    }
    return strlen(s);
}

char *mystrpbrk(const char *s, const char *accept)
{
    while(*s != '\0')
    {        
        for(int i = 0; i < strlen(accept); i++)
        {
            if(*s == accept[i]) return (char*)s;
        }
        s++;
    }    
    return NULL;
}

char *mystrstr(char *haystack, const char *needle)
{
	assert(haystack);
	assert(needle);
	int i, j, k;
	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = i, k = 0; needle[k] != '\0'&& haystack[j] == needle[k]; j++, k++){;}
		if (needle[k] == '\0' && k > 0) return &haystack[i];
	}
	return NULL;
}

bool isContained(const char *s, int c)
{
    while(*s != '\0')
    {
    	if(*s == c) return true;
    	s++;
    }
    return false;
}

char *mystrtok(char* str, const char* delim)
{
    static char *keep = NULL; char *tok = NULL;
    if(delim == NULL || str == NULL && keep == NULL) 
        return NULL;
    char table[255] = {0};
    int32_t size = 0;
    while (*delim != '\0')
    {
        if(isContained(table, *delim)) continue;
    	table[size++] = *delim;
    	delim++;
    }
    tok = str ? str : keep;
    while(*tok != '\0')
    {
    	if(isContained(table, *tok)) tok++; 
    	break;
    }
    str = tok;
    while(*tok)
    {
    	if(isContained(table, *tok))
    	{
    	    *tok++ = '\0'; break;
    	}
    	tok++;
    }
    keep = tok;
    return str == tok ? NULL : str;
}