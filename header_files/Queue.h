#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

void initialize_queue(int max);
void enqueue(int item, int *queue_arr);
void dequeue(int *queue_arr);
#endif