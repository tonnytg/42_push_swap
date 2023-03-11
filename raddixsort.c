#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10
#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} Stack;

void push(Stack *s, int x) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->items[++(s->top)] = x;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

void print(Stack *s) {
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

void radix_sort(Stack *s) {
    Stack bins[10];
    int digit = 0;
    while (digit < MAX_DIGITS) {
        // move items from stack to bins
        while (s->top >= 0) {
            int x = pop(s);
            int bin = (x / (int)pow(10, digit)) % 10;
            push(&bins[bin], x);
        }
        // move items from bins back to stack
        for (int i = 0; i < 10; i++) {
            while (bins[i].top >= 0) {
                push(s, pop(&bins[i]));
            }
        }
        digit++;
    }
}

int main() {
    Stack s = { -1, {} };
    push(&s, 123);
    push(&s, 45);
    push(&s, 789);
    push(&s, 23);
    push(&s, 67);
    push(&s, 1);

    printf("Before sorting:\n");
    print(&s);

    radix_sort(&s);

    printf("After sorting:\n");
    print(&s);

    return 0;
}
