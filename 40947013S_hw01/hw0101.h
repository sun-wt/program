#ifndef HW0101_H_INCLUDE
#define HW0101_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define number(x) x >= 48 && x <= 57
#define lower(x) x >= 97 && x <= 122
#define capital(x) x >= 65 && x <= 90 
#define exit_program printf("Invaild input.\n"),\
exit(0);

bool check_number(char *str);
bool check_end(char *str);
bool check_string(char *str);
bool check_value(int32_t value);
int32_t check_kind(char target);
int32_t reverse_bits(int32_t n);
int32_t change_type(char first, char second);

#endif