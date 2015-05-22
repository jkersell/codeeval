#include "stdio.h"

int main(int argc, char* argv[]) {
    FILE* input = fopen(argv[1], "r");

    int num = 0;
    unsigned int total = 0;
    while (fscanf(input, "%d", &num) != EOF) {
        while (num != 0) {
            if (num % 2 == 1) {
                ++total;
            }
            num = num >> 1;
        }
        printf("%d\n", total);
        total = 0;
    }

    return fclose(input);
}
