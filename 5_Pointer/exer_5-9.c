#include <stdio.h>
#include <sys/_types/_ssize_t.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (day > daytab[leap][month])
    {
        printf("error: input day %d exceeds maximum days of the input month %d",
               day, month);
        return -1;
    }
    if (month < 1 || month > 12)
    {
        printf("error: input month %d not exists!", month);
        return -1;
    }
    p = &daytab[leap][0];
    while (month-- > 0)
        day += *p++;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = &daytab[leap][0];
    while (yearday > *p)
        yearday -= *p++;
    *pmonth = p - &daytab[leap][0];
    *pday = yearday;
}

int main(void)
{
    int year[] = {2012, 2013, 2020, 2000, 1996};
    int yearday[] = {300, 1, 59};
    int pmonth, pday;
    pmonth = pday = 0;
    ssize_t year_size = sizeof(year) / sizeof(int);
    ssize_t yearday_size = sizeof(yearday) / sizeof(int);
    int i, j;
    for (i = 0; i < year_size; i++)
    {
        for (j = 0; j < yearday_size; j++)
        {
            month_day(year[i], yearday[j], &pmonth, &pday);
            printf("month %d day %d from year %d and yearday %d\n", pmonth,
                   pday, year[i], yearday[j]);
            printf("%d/%d/%d is %d day of year %d\n", year[i], pmonth, pday,
                   day_of_year(year[i], pmonth, pday), year[i]);
        }
    }
}
