#include <stdio.h>

float calculate_volume(float side_value) {
    float volume = side_value;

    for(int i = 0; i < 2; i++) {
        volume = volume * side_value;
    }

    return volume;
}

int main() {
    float side_value, volume;

    printf("\nInput the value for side of cube: \n");
    scanf("%f", &side_value);

    volume = calculate_volume(side_value);

    printf("\nVolume equals: %f\n", volume);

    return 1;
}