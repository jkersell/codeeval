#include "stdio.h"
#include "string.h"

#define INIT_SIZE 5

typedef struct Stack {
    char arr[INIT_SIZE];
    int size;
} Stack;

void stack_init(Stack* stack) {
    memset(stack->arr, 0, INIT_SIZE);
    stack->size = 0;
}

void stack_push(Stack* stack, char value) {
    stack->arr[stack->size] = value;
    stack->size++;
}

char stack_pop(Stack* stack) {
    stack->size--;
    return stack->arr[stack->size];
}

int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");

    Stack myStack;
    stack_init(&myStack);

    if (fp != NULL) {
        int c = fgetc(fp);
        while (c != EOF) {
            stack_push(&myStack, c);
            c = fgetc(fp);
            printf("%c", stack_pop(&myStack));
        }
    }

    fclose(fp);
}
