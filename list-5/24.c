#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 128
#define ALPHANUM_MAX 37

typedef struct CharCounter {
    char character;
    int counter;
} CharCounter;


int main() {
    char inputString[STR_SIZE];
    CharCounter counter[ALPHANUM_MAX];
    fgets(inputString, STR_SIZE, stdin);

    for (int i = 0; i < ALPHANUM_MAX; i++)
        counter[i].counter = 0;

    for (int inputIdx = 0; inputString[inputIdx] != '\n'; inputIdx++) {
        if (isalnum(inputString[inputIdx]))
            inputString[inputIdx] = toupper(inputString[inputIdx]);
            for (int countIdx = 0; countIdx < ALPHANUM_MAX; countIdx++)
                if (inputString[inputIdx] == counter[countIdx].character || counter[countIdx].counter == 0) {
                    counter[countIdx].counter++;
                    counter[countIdx].character = inputString[inputIdx];
                    break;
                }
    }
    
    for (int printIdx = 0; counter[printIdx].counter != 0; printIdx++)
        printf("%c  %5d\n", counter[printIdx].character, counter[printIdx].counter);

    return EXIT_SUCCESS;
}
