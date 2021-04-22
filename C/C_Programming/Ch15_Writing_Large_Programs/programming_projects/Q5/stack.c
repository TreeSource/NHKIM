#include "stack.h"

int top = 0;
int contents[STACK_SIZE] = {0};

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full (void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full()) {printf("Stack_overflow\n"); exit(0);}
    else contents[top++] = i;
}

int pop(void)
{
    if (is_empty()) {printf("Stack_underflow\n"); exit(0);}
    else return contents[--top];
}

