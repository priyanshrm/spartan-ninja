#include "header_files/DoublyLinkedList.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // printf("%d", getFavNumber());
    struct Node *head = NULL;
    int x[5] = {1, 3, 5, 7, 9};
    int *ptr = x;
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        insert(&head, *ptr);
        ptr++;
    }
    printDLL(&head);

    delete (&head, 0);
    printDLL(&head);
    delete (&head, 0);
    printDLL(&head);
    delete (&head, 0);
    printDLL(&head);
    delete (&head, 0);
    printDLL(&head);
    delete (&head, 0);
    printDLL(&head);
    delete (&head, 0);
    printDLL(&head);
    delete (&head, 0);
    printDLL(&head);
    return 0;
}
