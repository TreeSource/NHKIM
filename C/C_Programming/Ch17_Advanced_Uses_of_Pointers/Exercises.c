/* Chapter 17 exercise problems - P453 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right;};
struct rectangle *p;

struct {
    char *cmd_name;
    void (*cmd_pointer) (void);
} file_cmd[] = {
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
    {"close all", close_all_cmd},
    {"save", save_cmd},
    {"save as", save_as_cmd},
    {"save all", save_all_cmd},
    {"print", print_cmd},
    {"eixt", exit_cmd}
};

struct node 
{
    int value;
    struct node *next;
};

struct node *top = NULL;

void delete_node(struct node *p);


void *my_malloc(size_t n)
{
    void *p = malloc(n);
    if (p) return p;
    else {printf("mallocation failed\n"); exit(1);}
}

void add_to_list(struct node **list, int value)
{
    struct node *new_node;
    new_node = my_malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = *list;
    *list = new_node;
}

struct node *search_list(struct node *list, int value)
{
    for (; list != NULL && list->value != value; list = list->next);
    return list;
}

void delete_from_list(struct node **list, int value)
{
    struct node *p = *list;
    for (; p != NULL && p->value != value; p = p->next);
    delete_node(p);
}

void delete_all(struct node **list)
{
    struct node *p = *list, *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *list = NULL;
}

void delete_node(struct node *p)
{
    struct node *temp = p->next;
    p->value = temp->value;
    p->next = temp->next;
    free(temp);
}



char *duplicate(char *str)
{
    char *p = malloc(2 * strlen(str) + 1);
    strcpy(p, str);
    strcat(p, str);
    return p;
}

int *make_array(int n, int init)
{
    int *rtn = my_malloc(n * (sizeof(int))), *p = rtn, i;
    for (i = 0; i < n; *p++ = init, ++i);
    return rtn;
}

void make_empty(void)
{
    delete_all(&top);
}

bool is_empty(void)
{
    return top == NULL;
}

void push(int value)
{
    add_to_list(&top, value);
}

int pop(void)
{
    if(top == NULL) {printf("Stack underflow\n"); exit(1);}
    struct node *temp = top->next; int i = temp->value;
    top->value = temp->value;
    top->next = temp->next;
    free(temp);
    return i;
}

int count_occurences(struct node *list, int n)
{
    int count = 0;
    for (; list != NULL; list = list->next) if (list->value == n) count++;
    return count;
}

struct node *find_last(struct node *list, int n)
{
    struct node *last = list;
    for (; list != NULL; list = list->next) if (list->value == n) last= list;
    return list;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur = list, *prev = NULL, *new;
    while (cur->value <= new_node->value)
    {
        prev = cur;
        cur = cur->next;
    }
    new = malloc(sizeof(struct node));
    new->value = new_node->value;
    prev->next = new;
    new->next = cur;
    return list;
}

int sum(int (*f) (int), int start, int end)
{
    if (start > end) return 0;
    int i = start, rtn = 0;
    for (; i <= end; ++i) rtn += f(i);
    return rtn;
}

int main(void)
{
    char *ch_p; int iarr[100]; char command[11], ch;
    ch_p = duplicate("colin");
    printf("%s\n", ch_p);
    ch_p = command;
    while((ch = getchar()) != 0) if(ch_p < &command[11]) *ch_p++ = ch;
    *ch_p = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (strcmp(command, file_cmd[i].cmd_name)) {file_cmd[i].cmd_pointer; break;}
    }

    return 9;
}