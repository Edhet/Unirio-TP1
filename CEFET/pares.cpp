#include <stdio.h>

int main() {
    int max_number, odd = 0, even = 0, prime = 0;
    int is_not_prime;
    printf("Insert max number:\n >");
    scanf("%d", &max_number);

    for (int number = 1; number <= max_number; number++) {
        is_not_prime = 0;   // Poderia ser um bool, se não fosse C 😥

        if (number % 2 == 0) {
            even++;
        }
        else {
            odd++;

            for (int i = 2; i < number; i++) {
                if (number % i == 0) {
                    is_not_prime = 1;
                }
            }
            if (is_not_prime == 0) {
                prime++;
            }
            
        }
    }

    printf("Interval: %d\nNumber of odds: %d\nNumber of evens: %d\nNumber of primes: %d\n", max_number, odd, even, prime);

    return 0; 
}