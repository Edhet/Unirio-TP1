#include <stdio.h>

int main() {
    int max_number, start_interval, end_interval;
    int in = 0, out = 0;
    int is_in;

    printf("Insert max number:\n >");
    scanf("%d", &max_number);

    printf("Insert a start for interval:\n >");
    scanf("%d", &start_interval);

    printf("Insert a end for interval:\n >");
    scanf("%d", &end_interval);

    for (int num = 0; num < max_number; num++) {
        is_in = 0;
        for (int interval_num = start_interval; interval_num < end_interval; interval_num++) {
            if (num == interval_num) {
                is_in = 1;
            }
        }
        if (is_in == 1) {
            in++;
        }
        else {
            out++;
        }
    }

    printf("%d are INSIDE the interval.\n%d are OUTSIDE the interval.\n", in, out);

    return 0;
}