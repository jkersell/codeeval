#include "stdio.h"
#include "string.h"

#define INIT_SIZE 5

typedef struct Stack {
    char arr[INIT_SIZE];
} Stack;

void initStack(Stack* stack) {
    memset(stack->arr, 0, INIT_SIZE);
}

int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");

    Stack myStack;
    initStack(&myStack);

    if (fp != NULL) {
        int c = fgetc(fp);
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(fp);
        }
    }

    fclose(fp);
}
