#include <stdio.h>

int main()
{
    int n, v1, v2;
    scanf("%d %d %d", &n, &v1, &v2);

    for (int iter = 1; iter < n; iter++)
    {
        if (iter % v1 == 0) 
        {
            printf("%d ", iter);
        }
        else if (iter % v2 == 0)
        {
            printf("%d ", iter);
        }
    }
    printf("\n");
    
    return 0;
}
