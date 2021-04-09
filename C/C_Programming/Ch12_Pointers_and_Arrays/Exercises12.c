/* Chapter 11. Pointer Exercises */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Definitions */
#define STACK_SIZE 100
#define LEN 10

/* External variables */
int contents[STACK_SIZE];

/* Prototypes */
//Q1
void make_empty (int *);
bool is_empty (int *);
bool is_full (int *);
void push (int *, int);
int pop (int *);

void stack_overflow (void);
void stack_underflow (void);
//Q6
int sum_array (const int [], int);
//Q7
bool search (const int [], int, int);
//Q8
void store_zeros (int [], int);
//Q9
double inner_product (const double *, const double *, int);
//Q10
int *find_middle (int [], int);
//Q11
int find_largest (int [], int);
//Q12
void find_tw_largest (const int *, int, int *, int *);
//Q13
void initialize_ident (const double *, int);
//Q17
int sum_two_dimensional_array (const int [][LEN], int);

/* Main function */

int main (void)
{
    int temperatures[7][24], *temper_ptr = temperatures[0], cur, **temper_aptr;
    //Q14
    search(temperatures, 168, 32);
    //Q15
    for (; temper_ptr < &temperatures[6][23]; ++temper_ptr)
    {
        cur = temper_ptr - temperatures[0];
        if (cur % 7 == 0 && cur != 0) printf("\n");
        printf("%d ", *temper_ptr);
    }
    //Q16
    for (temper_aptr = temperatures; temper_aptr < &temperatures[7]; ++temper_aptr)
    {
        printf("%d ", find_largest(temper_aptr, 24));
    }
    return 0;
}

/* Functions */
void make_empty (int *top_ptr) {top_ptr = contents;}
bool is_empty (int *top_ptr) {return top_ptr == contents;}
bool is_full (int *top_ptr) {return top_ptr == &contents[STACK_SIZE - 1];}
void push (int *top_ptr, int i) 
{
    if (is_full(top_ptr)) stack_overflow();
    else *top_ptr++ = i;
}
int pop (int *top_ptr) 
{
    if (is_empty(top_ptr)) stack_underflow();
    else return *--top_ptr;
}

void stack_overflow(void) { exit(EXIT_FAILURE);}
void stack_underflow(void) {exit(EXIT_FAILURE);}

//Q6
int sum_array(const int array[], int n)
{
    int sum = 0, *array_pnt;
    for (array_pnt = array; array_pnt < &array[n - 1]; ++array_pnt) sum += *array_pnt;
    return sum;
}

//Q7
bool search(const int a[], int n, int key)
{
    int *array_pnt;
    for (array_pnt = a; array_pnt < a[n-1]; ++array_pnt) if (*array_pnt == key) return true;
    return false;
}

//Q8
void store_zeros(int a[], int n)
{
    int *array_pnt;
    for (array_pnt = a; array_pnt < a[n-1]; ++array_pnt) *array_pnt = 0;
}

//Q9
double inner_product (const double *a, const double *b, int n)
{
    double result;
    while (--n >= 0) result += *a++ * *b++;
    return result;
}

//Q10
int *find_middle (int a[], int n)
{
    int *p = a;
    for (int i = 0; i < n/2; ++i) p++;
    return p;
}

//Q11
int find_largest (int a[], int n)
{
    int *p = a, rtn;
    for (; p < &a[n-1], ++p) if (rtn < *p) rtn = *p;
    return rtn;
}

//Q12
void find_tw_largest (const int *a, int n, int *first_largest, int *second_largest)
{
    int *pnt = a;
    first_largest = second_largest = a;
    for (; pnt < &a[n-1]; ++pnt) if(*first_largest < *pnt) first_largest = pnt;
    for (pnt = a; pnt < &a[n-1]; ++pnt) if (*second_largest < *pnt && pnt != first_largest) second_largest = pnt;
}

//Q13
void initialize_ident (const double *a, int n)
{
    double *p = a; int count = n;
    for (; p < a[(n*n)-1]; ++p)
    {
        if (p == a) *p = 1.0;
        else if (count == 0) {*p = 1.0; count = n;}
        else {*p = 0.0; count--;}
    }
}

//Q17
int sum_two_dimensional_array (const int a[][LEN], int n)
{
    int *pnt = a[0], sum = 0;
    for (; pnt < &a[n-1][LEN]; ++pnt) sum += *pnt;
    return sum;
}