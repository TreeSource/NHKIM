#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100

int read_line(char str[], int n);
int compare_string(const void *p, const void *q);

int main (void)
{
    char *to_sort[MAX_WORDS], word[MAX_WORD_LENGTH + 1], *p;
    int len = 0, i = 0;
    for (;;)
    {
        if (i > MAX_WORDS)
        {
            printf("No more space.");
            break;
        }
        printf("Enter word: ");
        len = read_line(word, MAX_WORD_LENGTH);
        if (len == 0) break;
        p = malloc(len);
        strcpy(p, word);
        to_sort[i++] = p;
    }
    qsort(to_sort, i, sizeof(*to_sort), compare_string);
    printf("In sorted order: ");
    for(int j = 0; j < i; ++j) printf(" %s", to_sort[j]);
    printf("\n");
}

int compare_string(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n') if (i < n) str[i++] = ch;
    str[i] = '\0';
    return i;
}