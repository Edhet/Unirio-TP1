#include <stdio.h>

int main() {
    float weight, height;
    
    printf("\nInsert weight: \n");
    scanf("%f", &weight);
    printf("\nInsert height: \n");
    scanf("%f", &height);

    float imc = weight / (height * height);
    printf("\nYour IMC is: %2.1f\n", imc);

    if (imc < 20.0) {
        printf("You're below ideal weight.\n");
    }
    else if (imc >= 20.0 && imc < 25.0) {
        printf("You're ideal weight.\n");
    }
    else if (imc >= 25.0 && imc < 30.0) {
        printf("You're ideal weight.\n");
    }
    else if (imc >= 30.0 && imc < 35.0) {
        printf("You're obese.\n");
    }
    else {
        printf("You're morbidly obese.\n");
    }

    return 0;
}