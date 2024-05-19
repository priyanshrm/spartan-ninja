#include <stdio.h>
#include <stdlib.h>
#include "header_files/Queue.h"

int main(int argc, char const *argv[])
{
    int size = 5;
    int *queue_arr = (int *)malloc(size * sizeof(int));
    // int queue_arr[size];
    initialize_queue(size);
    for (int i = 0; i < size; i++)
    {
        enqueue((i + 1) * 5, queue_arr);
        if (i == 3)
            dequeue(queue_arr);
    }
    enqueue(18, queue_arr);
    enqueue(19, queue_arr);
    for (int i = 0; i < size; i++)
    {
        dequeue(queue_arr);
    }
    dequeue(queue_arr);
    free(queue_arr);
    return 0;
}
