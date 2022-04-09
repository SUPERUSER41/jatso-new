#include <stdio.h>
#include "../headers/date.h"

// Function to check leap year.
// Function returns 1 if leap year
int isLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

// returns 1 if given date is valid.
int isValidDate(Date *date)
{
    // check range of year,month and day
    if (date->year > MAX_YR ||
        date->year < MIN_YR)
        return 0;
    if (date->month < 1 || date->month > 12)
        return 0;
    if (date->day < 1 || date->day > 31)
        return 0;
    // Handle feb days in leap year
    if (date->month == 2)
    {
        if (isLeapYear(date->year))
            return (date->day <= 29);
        else
            return (date->day <= 28);
    }
    // handle months which has only 30 days
    if (date->month == 4 || date->month == 6 ||
        date->month == 9 || date->month == 11)
        return (date->day <= 30);
    return 1;
}