#include "../header_files/DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void printDLL(struct Node **head)
{
    struct Node *temp = *head;
    while (temp)
    {
        if (!temp->prev)
            printf("\nNULL<->");
        printf("[%d]<->", temp->data);
        if (!temp->next)
            printf("NULL\n");
        temp = temp->next;
    }
}

void insert(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    struct Node *temp = *head;
    if (temp == NULL)
    {
        *head = newNode;
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void delete(struct Node **head, int pos)
{
    int i = 0;
    struct Node *temp = *head;
    if (pos < 0 || temp == NULL)
    {
        printf("Position out of Scope\n");
        return;
    }

    if (pos == 0)
    {
        struct Node *tempX = temp->next;
        *head = tempX;
        if (tempX)
        {
            tempX->prev = NULL;
        }

        free(temp);
        return;
    }

    while (i != pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (i == pos - 1)
    {
        struct Node *tempX = temp->next;
        temp->next = tempX->next;
        tempX->next->prev = temp;
        free(tempX);
    }
    else
    {
        printf("Position out of Scope\n");
    }

    return;
}