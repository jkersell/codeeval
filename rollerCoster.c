#include "stdio.h"

int main(int argc, char* argv[]) {
    FILE* input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int current;
    do {
        current = fgetc(input);
        printf("%c", current);
    } while (current != EOF);

    return fclose(input);
}
