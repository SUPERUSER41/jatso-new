#ifndef DATE_H
#define DATE_H

#define MAX_YR 9999
#define MIN_YR 1900

typedef struct Date
{
    int year;
    int day;
    int month;
} Date;

int IsLeapYear(int year);
int IsValidDate(Date *date);

#endif