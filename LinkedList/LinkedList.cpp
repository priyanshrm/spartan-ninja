#include "../LinkedList/LinkedList.h"
#include "../Node/Node.h"
#include <iostream>

// LinkedList(int value);
//     ~LinkedList();
//     void printList();
//     void Reverse();
//     void append(int value);
//     void prepend(int value);
//     void insertAtIndex(int index, int value);
//     void deleteLast(int value);
//     void deleteFirst(int value);
//     bool deleteByIndex(int index);
//     bool deleteByValue(int value);
//     bool deleteNthNodeFromEnd(int index);
//     Node *getNodeByIndex(int index);
//     Node *getNodeByValue(int value);
//     Node *getMiddleNode();

LinkedList::LinkedList(int value)
{
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
    newNode->next = nullptr;
}

LinkedList::~LinkedList()
{
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
}

void LinkedList::printList()
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp;
        temp = temp->next;
    }
    std::cout << std::endl;
}