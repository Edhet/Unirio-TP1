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

    for (int num_for = 0; num_for < max_number; num_for++) {
        is_in = 0;
        for (int interval_num = start_interval; interval_num < end_interval; interval_num++) {
            if (num_for == interval_num) {
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

    in = 0;
    out = 0;
    int num_while = 0;
    while (num_while < max_number) {
        is_in = 0;
        for (int interval_num = start_interval; interval_num < end_interval; interval_num++) {
            if (num_while == interval_num) {
                is_in = 1;
            }
        }
        if (is_in == 1) {
            in++;
        }
        else {
            out++;
        }
        num_while++;
    }
    printf("%d are INSIDE the interval.\n%d are OUTSIDE the interval.\n", in, out);

    in = 0;
    out = 0;
    int num_do = 0;
    do {
        is_in = 0;
        for (int interval_num = start_interval; interval_num < end_interval; interval_num++) {
            if (num_do == interval_num) {
                is_in = 1;
            }
        }
        if (is_in == 1) {
            in++;
        }
        else {
            out++;
        }
        num_do++;
    } while (num_do < max_number);
    printf("%d are INSIDE the interval.\n%d are OUTSIDE the interval.\n", in, out);


    return 0;
}