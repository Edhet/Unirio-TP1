#include <stdio.h>

int main() {
    int number, result = 0;

    printf("Insert number:\n >");
    scanf("%d", &number);

    for (int iter = 1; iter < number; iter++) {
        if (number % iter == 0) {
        result += iter;
        }
    }
    
    if (result > number) {
        printf("The number is excessive.\n");
    }
    else {
        printf("The number is not excessive.\n");
    }

    return 0;
}