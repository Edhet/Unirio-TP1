#include <stdio.h>

int main()
{
    const int BASE_YEAR = 1600;
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
            for (int i = 0; i < 12; i++)
            {
                days_until_date += month_sizes[i];
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
                    days_until_date += day;
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
    days_until_date--;
    
    if (days_until_date % 7 == 0)
    {
        printf("\n saturday.\n");
    }
    else if (days_until_date % 7 == 1)
    {
        printf("\n sunday.\n");
    }
    else if (days_until_date % 7 == 2)
    {
        printf("\n monday.\n");
    }
    else if (days_until_date % 7 == 3)
    {
        printf("\n tuesday.\n");
    }
    else if (days_until_date % 7 == 4)
    {
        printf("\n wednesday.\n");
    }
    else if (days_until_date % 7 == 5)
    {
        printf("\n thursday.\n");
    }    
    else if (days_until_date % 7 == 6)
    {
        printf("\n friday.\n");
    }
    
    return 0;
}