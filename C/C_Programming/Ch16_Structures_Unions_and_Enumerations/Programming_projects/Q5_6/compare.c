#include <stdio.h>
#include "compare_dates.h"

int main(void)
{
    struct date d1, d2; int i;
    printf("Enter First date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &d1.month, &d1.day, &d1.year);
    printf("Enter Second date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &d2.month, &d2.day, &d2.year);
    i = compare_dates(d1, d2);
    if (i > 0) printf("%2d/%2d/%2d is earlier than %2d/%2d/%2d", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    else if (i < 0) printf("%2d/%2d/%2d is earlier than %2d/%2d/%2d", d1.month,d1.day,d1.year,d2.month,d2.day,d2.year);
    else printf("Those two dates are same date!");
    printf("\n");
    return 0;
}