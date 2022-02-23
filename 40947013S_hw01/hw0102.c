#include "hw0102.h"

int main() 
{
    char *ori_txt = calloc(4096, sizeof(int));
    printf("Please enter the original text: ");
    fgets(ori_txt, 4096, stdin);
    cut_end(ori_txt);

    char *key_word = calloc(64, sizeof(int));
    printf("Keyword: ");
    fgets(key_word, 64, stdin);
    cut_end(key_word);

    char *new_word = calloc(64, sizeof(int));
    printf("New word: ");
    fgets(new_word, 64, stdin);
    cut_end(new_word);

    printf("\n\n");

    check_keyword(ori_txt, key_word);
    printf("Before: \n");
    replace(ori_txt, key_word, new_word, 0);
    printf("After: \n");
    replace(ori_txt, key_word, new_word, 1);
    return 0;
}