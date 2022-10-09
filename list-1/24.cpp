#include <stdio.h>

int main() {
    int user_input;
    int ten = 0, twenty = 0, fifty = 0, hundred = 0;

    printf("\n Insert value to withdraw: \n");
    scanf("%d", &user_input);

    if (user_input % 10 != 0) {
        printf("\nChanging value to be divisible by 10.\n");
        while (user_input % 10 != 0) {
            user_input++;  
        }
    }

    while (user_input != 0) {
        if (user_input - 100 >= 0) {
            user_input -= 100;
            hundred++;
        }
        else if (user_input - 50 >= 0) {
            user_input -= 50;
            fifty++;
        }
        else if (user_input - 20 >= 0) {
            user_input -= 20;
            twenty++;
        }
        else if (user_input - 10 >= 0) {
            user_input -= 10;
            ten++;
        }
    }

    printf("\n%d '10 Reais' bills; \n%d '20 Reais' bills; \n%d '50 Reais' bills; \n%d '100 Reais' bills.\n", ten, twenty, fifty, hundred);

    return 1;
}