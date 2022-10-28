#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 3) {n = 3;}
    if (n % 2 == 0) {n++;}
    
    int asters = 1;
    int decrease = 0;

    for (int i = 0; i < n; i++)
    {
        if (asters >= n)
        {
            decrease = 1;
        }

        for (int sub_i = 0; sub_i < asters; sub_i++)
        {   
            printf("*");
            
        }
        printf("\n");
 
         if (decrease == 1)
        {
            asters -= 2;
        }
        else
        {
            asters += 2;
        }
    }
    
    return 0;
}
