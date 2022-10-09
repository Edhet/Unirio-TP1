#include <stdio.h>

int main() {
    float base, height;

    printf("\nInsert base: \n");
    scanf("%f", &base);
    printf("\nInsert height: \n");
    scanf("%f", &height);

    float triangle_area = base * height / 2;
    printf("\nTriangle area: %f\n", triangle_area);

    return 1;
}