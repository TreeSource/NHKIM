#include "compare_dates.h"

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year != d2.year) return d1.year < d2.year ? -1 : 1;
    else if (d1.month != d2.month) return d1.month < d2.month ? -1 : 1;
    else if (d1.day != d2.day) return d1.day < d2.day ? -1: 1;
    else return 0;
}