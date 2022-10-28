#include <stdio.h>

int main()
{
    int value = 3025, temp_val;
    for (int i = 1000; i < 9999; i++)
    {
        temp_val = i / 100 + i % 100;
        if (temp_val * temp_val == i) {
            printf(" {%d} ", i);
        }
    }
    return 0;
}
