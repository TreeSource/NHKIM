/* Find the largest and smallest elements in a array. */

#include <stdio.h>

#define N 10

void maxmin (int a[], int n, int* max, int* min);

int main (void)
{
    int b[N], i, big, small;
    
    printf("Enter %d Numbers: ", N);
    for (i = 0; i < N; ++i) scanf("%d", &b[i]);

    maxmin(b, N, &big, &small);

    printf("Largest: %d\nSmallest: %d\n", big, small);

    return 0;
}

void maxmin (int a[], int n, int* max, int* min)
{
    *min = *max = a[0];
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > *max) *max = a[i];
        else if (a[i] < *min) *min = a[i];
    }
}