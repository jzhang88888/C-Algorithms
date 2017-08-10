/*Stack (LIFO)*/
/*http://ide.geeksforgeeks.org/NuanKY*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
typedef struct stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

#define CAPACITY 100
 
Stack* create(unsigned capacity) {
    
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(capacity * sizeof(int));
    
    return stack;
}
 
int isFull (Stack* stack) {return stack->top == stack->capacity - 1;}
int isEmpty(Stack* stack) {return stack->top == -1;}
 
void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
int pop(Stack* stack) {
    
    if (isEmpty(stack)) return INT_MIN;
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) return INT_MIN;
    return stack->array[stack->top];
}

int main() {
    
    Stack* stack = create (CAPACITY);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
    printf("%d peek from stack\n", peek(stack));
    printf("%d peek from stack\n", peek(stack));
    return 0;
}
