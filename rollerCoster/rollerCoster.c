#include "stdio.h"
#include "stdbool.h"

int main(int argc, char* argv[]) {
    FILE* input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int current = fgetc(input);
    bool isUpper = true;
    while (current != EOF){
        if (current >= 97 && current <= 122) {
            if (isUpper) {
                current -= 32;
            }
            isUpper = !isUpper;
        } else if (current >= 65 && current <= 90) {
            if (!isUpper) {
                current += 32;
            }
            isUpper = !isUpper;
        } else if (current == 10) {
            isUpper = true;
        }
        printf("%c", current);
        current = fgetc(input);
    }

    return fclose(input);
}
