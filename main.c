#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    struct Node *tempPtr = *head;
    if (tempPtr == NULL)
    {
        *head = newNode;
        return;
    }

    while (tempPtr->next)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = newNode;
}

void insertAtStart(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    struct Node *tempPtr = *head;
    *head = newNode;
    newNode->next = tempPtr;
}

void deleteNode(struct Node **head, int pos)
{
    if (pos < 0 || *head == NULL)
    {
        printf("Invalid position or empty list.\n");
        return;
    }
    struct Node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    int i = 0;
    while (i != pos - 1)
    {
        if (temp)
        {
            temp = temp->next;
        }
        else
        {
            printf("POsition out of range.\n");
            return;
        }
    }

    struct Node *tempX = temp->next;
    temp->next = tempX->next;
    free(tempX);
}

void printSLL(struct Node **head)
{
    struct Node *tempPtr = *head;
    while (tempPtr)
    {
        printf("%d->", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    int x[5] = {1, 3, 5, 7, 9};
    struct Node *head = NULL;
    int *ptr = x;
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        insert(&head, *ptr);
        ptr++;
    }
    insertAtStart(&head, -1);
    printSLL(&head);

    deleteNode(&head, 0);
    printSLL(&head);
    deleteNode(&head, 0);
    printSLL(&head);
    deleteNode(&head, 0);
    printSLL(&head);
    deleteNode(&head, 0);
    printSLL(&head);
    deleteNode(&head, 0);
    printSLL(&head);
    deleteNode(&head, 0);
    printSLL(&head);
    deleteNode(&head, 0);
    printSLL(&head);

    return 0;
}
