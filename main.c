#include <stdio.h>
#include <stdlib.h>
#include "header_files/Stack.h"

int main(int argc, char const *argv[])
{
    int size = 5;
    int stack_arr[size];
    initialize_stack(size);
    for (int i = 0; i < size; i++)
    {
        push((i + 1) * 5, stack_arr);
    }
    push(11, stack_arr);
    for (int i = 0; i < size; i++)
    {
        pop(stack_arr);
    }
    pop(stack_arr);
    return 0;
}
