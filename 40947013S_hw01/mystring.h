#ifndef MYSTRING_H_INCLUDE
#define MYSTRING_H_INCLUDE

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


int change(int c);
long int mystrtol(const char *nptr, char **endptr , int base);
char *mystrchr(const char *s, int c);
char *mystrrchr(const char *s, int c);
size_t mystrspn(const char *s, const char *accept);
size_t mystrcspn(const char *s, const char *reject);
char *mystrpbrk(const char *s, const char *accept);
char *mystrstr(char *haystack, const char *needle);
bool isContained(const char *s, int c);
char *mystrtok(char* str, const char* delim);

#endif