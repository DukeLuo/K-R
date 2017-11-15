/* 练习　5-9 */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;

    leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
    p = daytab[leap];
    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > daytab[leap][month])
        return -1;
    while (--month)
        day += *++p;
    return day;
}


int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    *p = daytab[leap];
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return -1;
    }
    if (yearday < 1 || (leap == 0 && yearday > 365) || (leap == 1 && yearday > 366)) {
        *pmonth = -1;
        *pday = -1;
        return -1;
    }
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - daytab[leap];
    *pday = yearday;
}


