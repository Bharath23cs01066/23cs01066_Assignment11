#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char element);
char pop(Stack *stack);
int isEmpty(Stack *stack);

int main() {
    char input[MAX_SIZE];
    printf("Input a string: ");
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    printf("Reversed string using a stack is: ");

    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}

void push(Stack *stack, char element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}