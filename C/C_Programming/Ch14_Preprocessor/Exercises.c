#include <stdio.h>
#include <string.h>
#include <math.h>

#undef sqrt

#define unlong unsigned long
#define line (__LINE__)
#define file __FILE__
#define cube(x) ((x)*(x))
#define remainder(n) ((n)%4)
#define product_less_than_100(x, y) ((x) * (y) < 100 ? 1:0)
#define nelems(a) (sizeof((a)) / sizeof((a[0])))
#define DOUBLE(x) (2*(x))
#define TOUPPER(c) ('a' <= (c) && 'z' >= (c)?(c) - 'a' + 'A':(c))
#define DISP(f,x,y) (printf(#f "(" #x ") = %g\n" #f "(" #y ") = %g\n", f(x), f(y)))
#define GENERIC_MAX(type) \
type type##_max(type x, type y)  \
{return x > y ? x : y;}
#define CHECK(x,y,n) (((x > 0 && x < n) && (y > 0 && y < n)) ? 1 : 0)
#define MIN(x,y) (x < y ? x : y)
#define MEDIAN(x,y,z) (MIN(x,y) > MIN(y,z) ? MIN(x,y) : MIN(y,z))
#define POLYNOMIAL(x) (3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6)
#define ERROR(str, i) fprintf(stderr, str, i)


GENERIC_MAX(unlong)


int main(void)
{
    printf("%d\n", CHECK(2,5,7));
    printf("%d\n", MEDIAN(2,3,5));
    printf("%d\n", POLYNOMIAL(3));
    ERROR("Range error: index = %d\n", 3);
    #if !defined(M)
    printf("Not defined\n");
    #endif

    #if 0
    다음부터는 이걸 즐겨씁시다.
    #endif

    #if defined(ENGLISH)
    printf("Insert Disk 1\n");
    #elif defined(FRENCH)
    printf("Inserez Le Disque 1\n");
    #elif defined(SPANISH)
    printf("Inserte El Disco 1\n");
    #else
    printf("Inster Disk 1 (language was not defied)\n");
    #endif
    return 0;
}