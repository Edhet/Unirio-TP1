#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        for (int sub_i = 0; sub_i <= i; sub_i++)
        {
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}