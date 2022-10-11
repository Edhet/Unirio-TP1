#include <stdio.h>

int main() {
    float width, lenght, area, grass_price, cost;

    printf("\nInsert width in meters: \n");
    scanf("%f", &width);
    printf("\nInsert lenght in meters: \n");
    scanf("%f", &lenght);
    printf("\nInsert price per square meter of grass: \n");
    scanf("%f", &grass_price);

    area = width * lenght;
    cost = grass_price * area;
    printf("\n Total area to put grass: %3.1fm\n Total cost of grass for this area: $%3.1f\n", area, cost);

    return 0;
}