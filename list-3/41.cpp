#include <stdio.h>

int main()
{
    const int BASE_YEAR = 1600;
    const int LEAP_Y_DAYS = 366, NORM_Y_DAYS = 365;
    int year, month, day;
    int month_sizes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_until_date = 0;

    printf("Insert date: xx/xx/xxxx\n >");
    scanf("%d/%d/%d", &day, &month, &year);

    for (int iter_year = BASE_YEAR; iter_year <= year; iter_year++)
    {
        if (iter_year % 400 == 0) {
            month_sizes[1] = 29;
        }
        else if (iter_year % 100 != 0) {
            if (iter_year % 4 == 0) 
            {
            month_sizes[1] = 29;
            }
        }

        if (iter_year != year)
        {
            if (month_sizes[1] == 29) {
                days_until_date += LEAP_Y_DAYS;
            }
            else {
                days_until_date += NORM_Y_DAYS;
            }
        }
        else
        {
            if (month > 0 && month <= 12)
            {
                if (day <= month_sizes[month - 1] && day > 0)
                {
                    printf("\n %d/%d/%d is a valid date.\n", day, month, year);

                    for (int i = 0; i < month - 1; i++ )
                    {
                        days_until_date += month_sizes[i];
                    }
                    days_until_date += day - 1;
                    printf(" Day number %d from 1/1/1600.\n", days_until_date);
                }
                else
                {
                    printf("\nInvalid day\n");
                    break;
                }
            }
            else
            {
                printf("\nInvalid month\n");
            }
        }
        month_sizes[1] = 28;
    }
    
    int day_of_week = days_until_date % 7;
    switch (day_of_week)
    {
    case 0:
        printf("\nSaturday\n");
        break;
    case 1:
        printf("\nSunday\n");
        break;
    case 2:
        printf("\nMonday\n");
        break;
    case 3:
        printf("\nTuesday\n");
        break;
    case 4:
        printf("\nWednesday\n");
        break;
    case 5:
        printf("\nThursday\n");
        break;
    case 6:
        printf("\nFriday\n");
        break;
    }
    
    return 0;
}