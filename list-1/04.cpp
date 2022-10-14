#include <stdio.h>

int main() {
    int product_value, discount;

    printf("\nInsert product value: \n");
    scanf("%d", &product_value);
    printf("\nInsert discount percentage on product: \n");
    scanf("%d", &discount);

    if (discount > 100) {
        discount = 100;
    }
    else if (discount < 0) {
        discount = 0;
    }

    float final_value = product_value;
    final_value -= (float) product_value * ((float) discount / 100.0);

    printf("\n Product's final value is: $%2.1f\n", final_value);
    
    return 0;
}