#include <stdio.h>

int main() {
    int number, result = 0;

    printf("Insert number:\n >");
    scanf("%d", &number);

    for (int iter = 0; iter < number; iter++) {
        result += iter;
    }
    
    if (result > number) {
        printf("The number is excessive.\n");
    }
    else {
        printf("The number is not excessive.\n");
    }

    return 0;
}