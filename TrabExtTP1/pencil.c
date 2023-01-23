#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SquareTable {
    int size;
    int **contents;
} SquareTable;

void CreateSquareTable(int tableSize, SquareTable *table) {
    table->contents = malloc(tableSize * sizeof(int *));
    for (int i = 0; i < tableSize; i++)
        table->contents[i] = malloc(tableSize * sizeof(int));
    table->size = tableSize;
    
    char inputChar;
    for (int line = 0; line < tableSize; line++) {
        for (int colunm = 0; colunm < tableSize; colunm++) {
            scanf("%c", &inputChar);
            if (inputChar != '*' && inputChar != '0') {
                printf("The input value can only be '*' or '0'.\n");
                table->size = 0;
                return;
            }
            table->contents[line][colunm] = (inputChar == '*') ? -1 : 0;         
        }
        if ((inputChar = getchar()) != '\n') {
            printf("The input value is bigger than square size.\n");
            table->size = 0;
            return;
        }
    }
}

bool ContainsValue(const int value, const SquareTable table) {
    for (int line = 0; line < table.size; line++)
        for (int colunm = 0; colunm < table.size; colunm++)
            if (table.contents[line][colunm] == value)
                return true; 
    return false;
}

void ChangeValue(const int valueToChangeArround, const int value, SquareTable table) {
    if (!ContainsValue(-1, table))
        return;
    for (int line = 0; line < table.size; line++) {
        for (int colunm = 0; colunm < table.size; colunm++) {
            if (table.contents[line][colunm] == valueToChangeArround) {
                if (line +1 <= table.size -1 && table.contents[line + 1][colunm] == -1)
                    table.contents[line + 1][colunm] = value;
                if (line -1 >= 0 && table.contents[line - 1][colunm] == -1)
                    table.contents[line - 1][colunm] = value;
                if (colunm +1 <= table.size -1 && table.contents[line][colunm + 1] == -1)
                    table.contents[line][colunm + 1] = value;
                if (colunm -1 >= 0 && table.contents[line][colunm - 1] == -1)
                    table.contents[line][colunm - 1] = value;
            }
        }
    }
    ChangeValue(value, value + 1, table);
}

void PrintTable(const SquareTable table) {
    printf("\n");
    for (int line = 0; line < table.size; line++) {
        for (int colunm = 0; colunm < table.size; colunm++)
            printf("%d", (table.contents[line][colunm] > 9) ? 9 : table.contents[line][colunm]);
        printf("\n");
    }
}

void ClearStdin() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) (void)0;
}

int main() {
    int tableSize;
    printf("Input the table size.\n > ");
    scanf("%d", &tableSize);
    if (tableSize > 50 || tableSize < 3) {
        printf("The input value is %s.\n", (tableSize > 50) ? "bigger than 50" : "smaller than 3");
        return EXIT_FAILURE;
    }
    ClearStdin();

    SquareTable table;
    CreateSquareTable(tableSize, &table);

    if (table.size == 0)
        return EXIT_FAILURE;

    if (!ContainsValue(0, table) || !ContainsValue(-1, table) ) {
        printf("All the inputed characters are the same.\n");
        return EXIT_FAILURE;
    }

    ChangeValue(0, 1, table);
    PrintTable(table);

    return EXIT_SUCCESS;
}
