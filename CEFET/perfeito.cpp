#include <stdio.h>

int main() {
    int imper_number_counter = 0, sum;

    for (int number = 1; imper_number_counter != 10; number++) {
        sum = 0;

        for (int iter = 1; iter < number; iter++) {
            if (number % iter == 0) {
                sum += iter;
            }
        }
        if (sum != number) {
            imper_number_counter++;
            printf("\n%d is not Perfect.\n", number);
        }
    }

    return 0;
}