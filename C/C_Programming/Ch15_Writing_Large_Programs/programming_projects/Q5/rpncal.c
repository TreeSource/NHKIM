// Programming project Ch15_Q5 from programming project Ch10_Q6

#include "stack.h"

#define elif else if

int main (void)
{
    char ch; int operand1, operand2;
    for (;;)
    {
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '=')
        {
            if (ch == 'q') exit(0);
            elif (ch >= '0' && ch <= '9') push(ch - '0');
            elif (ch == '+')
            {
                operand1 = pop();
                operand2 = pop();
                operand1 += operand2;
                push(operand1);
            }
            elif (ch == '-')
            {
                operand1 = pop();
                operand2 = pop();
                operand1 -= operand2;
                push(operand1);
            }
            elif (ch == '*')
            {
                operand1 = pop();
                operand2 = pop();
                operand1 *= operand2;
                push(operand1);
            }
            elif (ch == '/')
            {
                operand1 = pop();
                operand2 = pop();
                operand1 /= operand2;
                push(operand1);
            }
        }
        printf("Value of expression: %d\n", contents[0]);
    }  
}