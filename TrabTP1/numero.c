#include <stdio.h>

int right(long long value, const int size, long long *K) {
    if (value <= 0)
        return 0;

    value = value % size;

    if (value != 0) {
        long long temp_K; 
        long long div_factor = 10, mult_factor = 100;

        for (int i = 0; i < size - 3; i++)
            mult_factor = mult_factor * 10;
        
        for (int i = 0; i < value; i++) {
            temp_K = (*K % div_factor) * mult_factor;
            *K = *K / div_factor + temp_K;
        }
    }
    return 1;
}

int left(long long value, const int size, long long *K) {
    if (value <= 0)
        return 0;

    value = value % size;

    if (value != 0) {
        long long temp_K; 
        long long div_factor = 100, mult_factor = 10;

        for (int i = 0; i < size - 3; i++)
            div_factor = div_factor * 10;

        for (int i = 0; i < value; i++) {
            temp_K = (*K % div_factor) * mult_factor;
            *K = *K / div_factor + temp_K;
        }
    }
    return 1;
}

int start(const long long value, const int size, long long *K) {
    if (value < 0 || value > 9)
        return 0;

    long long div_factor = 100;
    for (int i = 0; i < size - 3; i++)
        div_factor = div_factor * 10;
    
    *K = *K / 10 + (value * div_factor);
    return 1;
}

int end(const long long value, const int size, long long *K) {
    if (value < 0 || value > 9)
        return 0;

    long long unwanted = *K; 
    long long div_factor = 100;
    for (int i = 0; i < size - 2; i++)
        div_factor = div_factor * 10;
    for (int i = 0; i < size - 1; i++)
        unwanted = unwanted / 10;

    unwanted = unwanted * div_factor;
    *K = (*K * 10 - unwanted) + value;
    return 1;
}

int main() {
    long long value, K = 0;
    int success_op, digit_count = 0;
    char operation;
    char c;

    while (1) {
        digit_count = 0;   
        printf("Value of K: ");
        scanf("%lld", &K);
        if ((c = getchar()) != '\n' && c != EOF) {
            printf("Wrong input, type again.\n");
            while((c = getchar()) != '\n' && c != EOF)
                (void)0;
        }
        else if (K > 0) {
            long long temp_K = K;
            while (temp_K != 0) {
                temp_K = (temp_K >= 10) ? temp_K / 10 : 0;
                digit_count++;
            }

            if ( digit_count >= 3 && digit_count <= 11)
                break;
            else
                printf("Please insert a number with 3 up to 11 characters.\n");
        }
        else
            printf("Wrong input, type again.\n");
    }

    while (1) {
        printf("Operation: ");
        scanf("%c", &operation);
        if (operation == 't' || operation == 'T')
            break;
        scanf("%lld", &value);
        if ((c = getchar()) != '\n' && c != EOF) {
            printf("Wrong value, type again.\n");
            while((c = getchar()) != '\n' && c != EOF)
                (void)0;
        }
        else {
            switch (operation) {
                case 'd':
                case 'D':
                    success_op = right(value, digit_count, &K);
                    if (!success_op)
                        printf("Wrong operation. Value must be 1 or bigger.\n");
                    break;
                case 'e':
                case 'E':
                    success_op = left(value, digit_count, &K);
                    if (!success_op)
                        printf("Wrong operation. Value must be 1 or bigger.\n");
                    break;
                case 'i':
                case 'I':
                    success_op = start(value, digit_count, &K);
                    if (!success_op)
                        printf("Wrong operation. Value must be between 1 and 9.\n");
                    break;
                case 'f':
                case 'F':
                    success_op = end(value, digit_count, &K);
                    if (!success_op)
                        printf("Wrong operation. Value must be between 1 and 9.\n");
                    break;
                default:
                    printf("Operation doesn't exist.\n");
                    break;
            }
        }
        if (success_op) {
            long long check_K = K;
            int check_digits = 0;
            while (check_K != 0) {
                check_K = (check_K >= 10) ? check_K / 10 : 0;
                check_digits++;
            }
            if (check_digits != digit_count) {
                check_digits = digit_count - check_digits;
                for (int i = 0; i < check_digits; i++)
                    printf("0");
            }

            if (K != 0)
                printf("%lld\n", K);
            else
                printf("\n");
        }
    }
    return 0;
}