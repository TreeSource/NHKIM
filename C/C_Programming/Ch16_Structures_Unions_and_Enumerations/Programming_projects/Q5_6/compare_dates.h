#ifndef COMPARE_DATES_H
#define COMPARE_DATES_H
struct date
{
    int month, day, year;
};

int compare_dates(struct date d1, struct date d2);
#endif