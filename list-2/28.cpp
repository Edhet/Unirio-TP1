#include <stdio.h>

int main() {
    int start, end, div_check;
    int num_counter = 0, div_counter = 0;

    printf("\nInput start of the interval: \n");
    scanf("%d", &start);
    printf("\nInput end of the interval: \n");
    scanf("%d", &end);
    printf("\nInput number to check the divisibility: \n");
    scanf("%d", &div_check);

    for (int iterator = start; iterator < end; iterator++) {
        num_counter++;

        if (iterator % div_check == 0) {
            div_counter++;
        }
    }

    printf("\nNumbers in the interval: %d \nNumbers divisible by %d in the interval: %d\n", num_counter, div_check, div_counter);
    return 0;
}