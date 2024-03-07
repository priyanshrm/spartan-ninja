#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Node/Node.h"

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    LinkedList(int value);
    ~LinkedList();
    void printList();
    void reverse();
    void append(int value);
    void prepend(int value);
    void insertAtIndex(int index, int value);
    void deleteLast(int value);
    void deleteFirst(int value);
    bool deleteByIndex(int index);
    bool deleteByValue(int value);
    bool deleteNthNodeFromEnd(int index);
    Node *getNodeByIndex(int index);
    Node *getNodeByValue(int value);
    Node *getMiddleNode();
};

#endif
