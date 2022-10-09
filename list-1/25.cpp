#include <stdio.h>

int main() {
    int total_value, entry, first, second, parts_sum;

    printf("\nInput product total price: \n");
    scanf("%d", &total_value);

    entry = total_value /3;
    first = total_value /3;
    second = total_value /3;

    parts_sum = entry + first + second;
    if (parts_sum < total_value) {
        entry += total_value - parts_sum;
    }

    printf("Total value: %d, Entry: %d, First installment: %d, Second installment: %d\n", total_value, entry, first, second);

    return 1;
}