#include <stdio.h>

int right(int value, const int size, long long *K) {
    if (value <= 0) {
        printf("Wrong value.\n");        
        return 1;
    }
    value = (value / size) + (value % size);
    if (value > size) value = value % size;
    
    long long temp_K = *K; 
    long long div_factor = 10, mult_factor = 10;

    for (int i = 0; i < value - 1; i++)
        div_factor = div_factor * 10;

    for (int i = 0; i < size - (value + 1); i++)
        mult_factor = mult_factor * 10;
    
    temp_K = (temp_K % div_factor) * mult_factor;
    *K = *K / div_factor + temp_K;

    return 0;
}

int left(int value, const int size, long long *K) {
    if (value <= 0) {
        printf("Wrong value.\n");        
        return 1;
    }
    value = (value / size) + (value % size);
    if (value > size) value = value % size;
    

    long long temp_K = *K; 
    long long div_factor = 10, mult_factor = 10;

    for (int i = 0; i < size - (value + 1); i++)
        div_factor = div_factor * 10;

    for (int i = 0; i < value - 1; i++)
        mult_factor = mult_factor * 10;

    temp_K = (temp_K % div_factor) * mult_factor;
    *K = *K / div_factor + temp_K;
    
    return 0;
}

int start(const int value, const int size, long long *K) {
    if (value <= 0 && value >= 9) {
        printf("Wrong value.\n");        
        return 1;
    }

    long long div_factor = 1;
    for (int i = 0; i < size - 1; i++)
        div_factor = div_factor * 10;
    
    *K = *K / 10 + (value * div_factor);
    return 0;
}

int end(const int value, const int size, long long *K) {
    if (value <= 0 && value >= 9) {
        printf("Wrong value.\n");        
        return 1;
    }

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
    int value, digit_count = 0;
    char operation;
    
    char c;

    while (1) {    
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
                right(value, digit_count, &K);
                break;
            case 'e':
            case 'E':
                left(value, digit_count, &K);
                break;
            case 'i':
            case 'I':
                start(value, digit_count, &K);
                break;
            case 'f':
            case 'F':
                end(value, digit_count, &K);
                break;
            default:
                printf("Operation doesn't exist.\n");
                break;
            }
        }
        printf("%lld\n", K);
    }
    return 0;
}