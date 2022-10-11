#include <stdio.h>


int main() {
    const int feat_count = 4;

    int value = 150000, air = 1750, metalic = 800, electric_window = 1200, hidraulic_steering = 2000;

    char input[feat_count];

    printf("Insert features.\n");
    scanf("%s", &input);

    for (int index = 0; index < feat_count; index++) {
        if (input[index] == 'A') {
            value += air;
        }
        else if (input[index] == 'B') {
            value += metalic;
        }
        else if (input[index] == 'C') {
            value += electric_window;
        }
        else if (input[index] == 'D') {
            value += hidraulic_steering;
        }
    }
    
    printf("Final price: %d\n", value);

    return 0;
}