/* Adds two fractions */

#include <stdio.h>

int smaller (int, int);

int main (void)
{
    int num1, denom1, num2, denom2, result_num, result_denom, div, cnt;

    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    cnt = 1;

    while (cnt <= smaller(result_denom, result_num)) 
    {
        if (result_denom % cnt == 0 && result_num % cnt == 0)
        {
            div = cnt;
        }
        cnt++;
    }

    result_num /= div;
    result_denom /= div;

    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}

int smaller(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else if (b < a)
    {
        return b;
    }
    else 
    {
        return a;
    }
}