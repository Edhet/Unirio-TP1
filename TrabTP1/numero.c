#include <stdio.h>

int right(int value, const int size, long long *K) {
    if (value <= 0)
        return 1;

    value = value % size;

    if (value != 0) {
        long long temp_K; 
        long long div_factor = 10, mult_factor = 10;

        for (int i = 0; i < size - 2; i++)
            mult_factor = mult_factor * 10;
        
        for (int i = 0; i < value; i++) {
            temp_K = (*K % div_factor) * mult_factor;
            *K = *K / div_factor + temp_K;
        }
    }
    return 0;
}

int left(int value, const int size, long long *K) {
    if (value <= 0)
        return 1;

    value = value % size;

    if (value != 0) {
        long long temp_K; 
        long long div_factor = 10, mult_factor = 10;

        for (int i = 0; i < size - 2; i++)
            div_factor = div_factor * 10;

        for (int i = 0; i < value; i++) {
            temp_K = (*K % div_factor) * mult_factor;
            *K = *K / div_factor + temp_K;
        }
    }
    return 0;
}

int start(const int value, const int size, long long *K) {
    if (value < 0 || value > 9)
        return 1;

    long long div_factor = 1;
    for (int i = 0; i < size - 1; i++)
        div_factor = div_factor * 10;
    
    *K = *K / 10 + (value * div_factor);
    return 0;
}

int end(const int value, const int size, long long *K) {
    if (value < 0 || value > 9)
        return 1;

    long long unwanted = *K; 
    long long div_factor = 10;
    for (int i = 0; i < size - 1; i++)
        div_factor = div_factor * 10;
    for (int i = 0; i < size - 1; i++)
        unwanted = unwanted / 10;

    unwanted = unwanted * div_factor;
    *K = (*K * 10 - unwanted) + value;

    return 0;
}

int main() {
    long long K;
    int op_error, value, digit_count = 0;
    char operation;
    char c;

    while (1) { 
        digit_count = 0;   
        printf("Value of K: ");
        scanf("%lld", &K);
        if (K > 0) {
            if ((c = getchar()) != '\n' && c != EOF) {
                printf("Wrong input, type again.\n");
                while((c = getchar()) != '\n' && c != EOF)
                    (void)0;
            }
            else {
            long long temp_K = K;
            while (temp_K != 0) {
                    if (temp_K >= 10) {
                        temp_K = temp_K / 10;
                        digit_count++;
                    }
                    else if (temp_K < 10 && temp_K >= 0) {
                        temp_K = 0;
                        digit_count++;
                    }
                }
            
                if (digit_count <= 11 && digit_count >= 3)
                    break;
                else
                    printf("Please insert a number with 3 up to 11 characters.\n");
            }   
        }
        else
            printf("Wrong input, type again.\n");
    }

    while (1) {
        printf("Operation: ");
        scanf("%c", &operation);
        if (operation == 't' || operation == 'T')
            break;
        scanf("%d", &value);
        if ((c = getchar()) != '\n' && c != EOF) {
            printf("Wrong value, type again.\n");
            while((c = getchar()) != '\n' && c != EOF)
                (void)0;
        }
        else {
            switch (operation) {
            case 'd':
            case 'D':
                op_error = right(value, digit_count, &K);
                break;
            case 'e':
            case 'E':
                op_error = left(value, digit_count, &K);
                break;
            case 'i':
            case 'I':
                op_error = start(value, digit_count, &K);
                break;
            case 'f':
            case 'F':
                op_error = end(value, digit_count, &K);
                break;
            default:
                printf("Operation doesn't exist.\n");
                break;
            }
        }
        if (op_error) {
            printf("Wrong value.\n");     
        }   
        else {
            long long check_K = K;
            int check_digits = 0;
            while (check_K != 0) {
                if (check_K >= 10) {
                    check_K = check_K / 10;
                    check_digits++;
                }
                else if (check_K < 10 && check_K >= 0) {
                    check_K = 0;
                    check_digits++;
                }
            }
            if (check_digits != digit_count) {
                check_digits = digit_count - check_digits;
                for (int i = 0; i < check_digits; i++)
                    printf("0");
            }
            printf("%lld\n", K);
        }
    }
    return 0;
}