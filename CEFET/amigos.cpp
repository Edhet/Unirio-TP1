#include <stdio.h>

void two_entry_frien() {
    int first, second, sum;

    printf("Insert first number:\n >");
    scanf("%d", &first);

    printf("Insert second number:\n >");
    scanf("%d", &second);

    for (int num = 1; num < first; num++) {
        if (first % num == 0) {
            sum += num;
        }
    }
    if (sum == second) {
        printf("\nThey're friends! 🤗\n");
    }
    else {
        printf("\nThey're NOT friends! 😠\n");
    }
}

void one_entry_frien() {
    int frien_counter = 0, target_num, sum;
    printf("Insert number:\n >");
    scanf("%d", &target_num);

    for (int num = 1; num < target_num; num++) {
        sum = 0;
        for (int div = 1; div < num; div++) {
            if (num % div == 0) {
                sum += div;
            }
        }
        if (sum == target_num) {
            frien_counter++;
        }
    }
        printf("\nHe has %d friens! 🤗\n", frien_counter);

}

int main() {
    two_entry_frien();
    one_entry_frien();

    return 0;
}