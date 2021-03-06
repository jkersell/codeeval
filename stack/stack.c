#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Stack {
    char* arr;
    int size;
    int maxSize;
} Stack;

void grow(Stack* stack) {
    stack->maxSize *= 2;
    char* newArr = (char*) malloc(stack->maxSize * sizeof(char));
    memcpy(stack->arr, newArr, stack->size);
    stack->arr = newArr;
}

void stack_init(Stack* stack, int initSize) {
    stack->maxSize = initSize;
    stack->size = 0;
    stack->arr = (char*) malloc(initSize * sizeof(char));
}

void stack_push(Stack* stack, char value) {
    if (stack->size == stack->maxSize) {
        grow(stack);
    }
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
    stack_init(&myStack, 5);

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
