/* Chapter 11. Pointer Exercises */

//Q1: d, f
//Q2: e, f

#include <stdio.h>

// Prototypes
//Q3
void avg_sum3 (double [], int, double *, double *);
//Q4
void swap (int *, int *);
//Q5
void split_time (long, int *, int *, int *);
//Q6
void find_two_largest (int [], int, int *, int *);

// Main Function
int main (void)
{
    //Q3
    printf("\nQ3\n");
    double avg3, sum3, a3[] = {1.0, 2.0, 3.0, 4.0};
    avg_sum3 (a3, 4, &avg3, &sum3);
    printf("average: %f\nsum: %f\n", avg3, sum3);

    //Q4
    printf("\nQ4\n");
    int a4 = 5, b4 = 10;
    printf("num1: %d\tnum2: %d\n", a4, b4);
    swap (&a4, &b4);
    printf("num1: %d\tnum2: %d\n", a4, b4);

    //Q5
    printf("\nQ5\n");
    long secs = 1000000;
    int hr5, min5, sec5;
    split_time (secs, &hr5, &min5, &sec5);
    printf("The total seconds was: %lds, it can converted to:\n%d:%d:%d\n", secs, hr5, min5, sec5);

    //Q6
    printf("\nQ6\n");
    int a6[] = {1, 4, 5, 2, 3, 7, 6}, lrg6, slrg6;
    find_two_largest(a6, 7, &lrg6, &slrg6);
    printf("The largest: %d, Second largest: %d\n", lrg6, slrg6);

    return 0;
}

// Functions
//Q3
void avg_sum3 (double a3[], int n3, double *avg3, double *sum3)
{
    int i; 
    
    *sum3 = 0.0;
    for (i = 0; i < n3; ++i) *sum3 += a3[i];
    *avg3 = *sum3 / n3;
}
//Q4
void swap (int *p4, int *q4)
{
    int temp = *q4;
    *q4 = *p4;
    *p4 = temp;
}
//Q5
void split_time (long total_sec5, int *hr5, int *min5, int *sec5)
{
    *sec5 = total_sec5 % 60;
    *min5 = (total_sec5 % 3600) / 60;
    *hr5 = (total_sec5 % 14400) / 3600;
}
//Q6
void find_two_largest (int a6[], int n6, int *largest6, int *second_largest6)
{
    int i, flrgin;
    for (i = 0; i < n6; ++i)
    {
        if (*largest6 < a6[i]) {*largest6 = a6[i]; flrgin = i;}
    }
    for (i = 0; i < n6; ++i) 
    {
        if (i != flrgin && *second_largest6 < a6[i]) *second_largest6 = a6[i];
    }
}