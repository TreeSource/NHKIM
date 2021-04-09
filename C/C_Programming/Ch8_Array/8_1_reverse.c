/* Reverses a series of numbers */
#include <stdio.h>
#define N 10

int main (void)
{
    int a[N], i;
    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
    printf("In inverse order: ");
    for (int i = N; i >0; --i) printf("%d", a[i - 1]);
    printf("\n");

    return 0;
}