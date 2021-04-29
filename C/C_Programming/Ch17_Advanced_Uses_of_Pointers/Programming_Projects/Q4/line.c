/* Programming projects Ch17_Q4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node
{
    int len;
    struct node *next;
    char word[];
};

struct node *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    line = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    int n = strlen(word);
    struct node *new_node = malloc(sizeof(struct node) + n), *p = line;
    new_node->len = n;
    strcpy(new_node->word, word);
    new_node->next = NULL;
    if (p == NULL) p = new_node;
    else 
    {
        for(int i = 0; i < num_words; ++i, p = p->next);
        p->next = new_node;
    }
    line_len += n;
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    struct node *p = line;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (; p != NULL; p = p->next)
    {   
        for(int i = 0; i < p->len; ++i) putchar(p->word[i]);
        spaces_to_insert = extra_spaces / (num_words - 1);
        for (j = 0; j < spaces_to_insert; ++j) putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void)
{
    if (line_len > 0)
    {
        struct node *p = line;
        for (; p != NULL; p = p->next)
        {
            for(int i = 0; i < p->len; ++i) putchar(p->word[i]);
        }
    }
}