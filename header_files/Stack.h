#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

void initialize_stack(int stack_max);
void push(int item, int *stack_arr);
void pop(int *stack_arr);
int peek(int *stack_arr);

#endif