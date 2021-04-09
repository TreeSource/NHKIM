/* Check numbers for repeated digits */
#include <stdio.h>
#include <stdbool.h> // C99 Only

int main (void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    for (; n > 0; n /= 10) {
        digit = n % 10;
        if (digit_seen[digit]) break;
        digit_seen[digit] = true;
    }

    if (n > 0) printf("Repeated digit\n");
    else printf("No repeated digit\n");

    return 0;
}