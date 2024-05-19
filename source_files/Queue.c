#include "../header_files/Queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int queue_max;
    int front;
    int rear;
} Queue;

Queue *q1;

void initialize_queue(int max)
{
    q1 = (Queue *)malloc(sizeof(Queue));
    if (q1 == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q1->front = -1;
    q1->rear = 0;
    q1->queue_max = max;
}

void enqueue(int item, int *queue_arr)
{

    if (q1->rear == q1->front)
    {
        printf("Queue overflow\n");
        return;
    }
    queue_arr[q1->rear] = item;
    printf("inserted %d at %d\n", item, q1->rear);
    q1->rear = (q1->rear + 1) % q1->queue_max; // modulo increment
    if (q1->front == -1)
    {
        q1->front = 0;
    }
}

void dequeue(int *queue_arr)
{
    if (q1->front == -1 || queue_arr[q1->front] == 0)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("removed %d from %d\n", queue_arr[q1->front], q1->front);
    queue_arr[q1->front] = 0;
    q1->front = (q1->front + 1) % q1->queue_max; // modulo increment
}
