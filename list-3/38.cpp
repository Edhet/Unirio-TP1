#include <stdio.h>

int main()
{
    int x = 1, y = 0, z;
    int n;
    scanf("%d", &n);
    if (n < 2) {n = 2;}
    for (int i = 0; i < n; i++)
    {
        z = x + y;
        y = x;
        x = z;
        printf(" %d ", z);
    }
    return 0;
}
