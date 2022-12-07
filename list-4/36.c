#include <stdio.h>
#include <stdlib.h>

int main() {
    const int SIZE = 12;
    const int HEIGHT = 20;
    const int MONTH_SIZE = 4;
    
    char months[SIZE][MONTH_SIZE] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int columnPercentages[SIZE];
    int inpBuffer;

    int graph[HEIGHT][SIZE];

    printf("INSERT 12 integers...\n");

    for (int i = 0; i < SIZE; i++) {
        do {  
        printf("Insert the %d month percentage\n> ", i + 1);
        scanf("%d", &inpBuffer);
        if (inpBuffer > 100 || inpBuffer < 0)
            printf("Insert a valid percentage.\n");        
        } while (inpBuffer > 100 || inpBuffer < 0);

        columnPercentages[i] = (inpBuffer / 5) * 5;
    }

    for (int line = HEIGHT-1; line >= 0; line--) {
        for (int column = 0; column < SIZE; column++) {
            if (columnPercentages[column] > 0) {
                graph[line][column] = 1;
                columnPercentages[column] -= 5;
            }
            else
                graph[line][column] = 0;
        }
    }

    int columnValue = 100;
    for (int line = 0; line < HEIGHT; line++) {
        printf("%3d |", columnValue);
        for (int column = 0; column < SIZE; column++) {
            if (graph[line][column] == 1)
                printf(" *** ");
            else
                printf("     ");
        }
        columnValue -= 5;
        printf("\n");
    }
    printf("    ");
    for (int m = 0; m < SIZE; m++)
        printf("  %s", months[m]);
    printf("\n");

    return EXIT_SUCCESS;
}
