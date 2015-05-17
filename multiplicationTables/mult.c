#include "stdio.h"

int main(int argc, char* argv[]) {
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <=12; ++j) {
            int product = i * j;
            printf("%4d", product);
        }
        printf("\n");
    }
}
