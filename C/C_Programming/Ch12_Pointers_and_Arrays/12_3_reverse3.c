/* Reverses a seires of numbers (pointer version) */


#include <stdio.h>

int main (void)
{
    int n, *p; printf("Type a size of series: "); scanf("%d", &n); int a[n];

    printf("Enter %d Numbers: ", n);
    for (p = a; p < a + n; ++p) scanf(" %d", p);
    printf("In reverse order: "); --p;
    for (; p >= a; --p) printf(" %d", *p);
    printf("\n");

    return 0;
}