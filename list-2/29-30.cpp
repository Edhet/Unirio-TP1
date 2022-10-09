#include <stdio.h>

int main() {
    int year, month, day;
    int month_sizes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_until_date = 0;

    printf("\nInput year: \n");
    scanf("%d", &year);
    printf("\nInput month: \n");
    scanf("%d", &month);
    printf("\nInput day: \n");
    scanf("%d", &day);

    if (year % 400 == 0) {
        month_sizes[1] = 29;
    }
    else if (year % 100 != 0) {
        if (year % 4 == 0) {
        month_sizes[1] = 29;
        }
    }

    if (month > 0 && month <= 12) {
        if (day <= month_sizes[month - 1] && day > 0) {
            printf("\n %d/%d/%d is a valid date.\n", day, month, year);

            for (int i = 0; i < month - 1; i++ ) {
                days_until_date += month_sizes[i];
            }
            days_until_date += day;
            printf(" Day number %d of the year.\n", days_until_date);
        }
        else {
            printf("\nInvalid day\n");
        }
    }
    else {
        printf("\nInvalid month\n");
    }

    return 1;
}