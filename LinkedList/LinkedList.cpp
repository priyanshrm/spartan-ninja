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

void LinkedList::reverse()
{
    if (length <= 1)
        return;
    Node *temp = head;
    head = tail;
    tail = temp;
    Node *pre = nullptr;
    Node *after = temp->next;
    while (temp)
    {
        after = temp->next;
        temp->next = pre;
        pre = temp;
        temp = after;
    }
}

void LinkedList::append(int value)
{
    Node *newNode = new Node(value);
    if (tail)
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::prepend(int value)
{
    Node *newNode = new Node(value);
    if (head)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::insertAtIndex(int index, int value)
{
    if (index < 0 || index > length)
    {
        std::cout << "index out of scope" << std::endl;
        return;
    }
    if (index == 0)
    {
        return prepend(value);
    }
    if (index == length)
    {
        return append(value);
    }
    Node *newNode = new Node(value);
    int i = 0;
    Node *temp = head;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}