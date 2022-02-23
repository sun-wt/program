#ifndef HW0102_H_INCLUDE
#define HW0102_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define exit_program printf( "Invaild input.\n" ),\
exit(0);
#define RED "\x1B[0;31m"
#define RESET "\x1B[0m"

void cut_end(char *input);
bool check_keyword(char *table, char *target);
bool punctuation_marks(char *token, char *target);
void replace(char *table, char *target, char *replace, bool flag);

#endif