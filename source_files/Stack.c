#include "../header_files/Stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int stack_max;
    int stack_top;
} Stack;

Stack *s1;

void initialize_stack(int stack_max)
{
    s1 = (Stack *)malloc(sizeof(Stack)); // cannot directly initialize global variables with dynamic memory
    if (s1 == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    s1->stack_max = stack_max;
    s1->stack_top = -1;
}

void push(int item, int *stack_arr)
{
    if (s1->stack_top == s1->stack_max - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack_arr[++(s1->stack_top)] = item;
    printf("%d added to stack at %d\n", item, s1->stack_top);
}

void pop(int *stack_arr)
{
    if (peek(stack_arr))
    {
        stack_arr[s1->stack_top--] = 0;
    }
}

int peek(int *stack_arr)
{
    if (s1->stack_top == -1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    printf("%d\n", stack_arr[s1->stack_top]);
    return stack_arr[s1->stack_top];
}