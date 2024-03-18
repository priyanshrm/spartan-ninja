#include "../LinkedList/LinkedList.h"
#include "../Node/Node.h"
#include <iostream>

//     void deleteLast(int value);
//     void deleteFirst(int value);
//     bool deleteByIndex(int index);
//     bool deleteByValue(int value);
//     Node *getNodeByIndex(int index);
//     Node *getNodeByValue(int value);
//     bool deleteNthNodeFromEnd(int index);
//     Node *getMiddleNode();

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

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
    length++;
}

void LinkedList::deleteLast()
{
    if (length == 0)
    {
        std::cout << "No node found in the list!" << std::endl;
        return;
    }
    Node *temp = head;
    if (length == 1)
    {
        delete temp;
        head = nullptr;
        tail = nullptr;
    }
    while (temp)
    {
        if (temp->next == tail)
        {
            tail = temp;
            Node *last = temp->next;
            delete last;
            tail->next = nullptr;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    length--;
}

void LinkedList::deleteFirst()
{
    if (length == 0)
    {
        std::cout << "No node found in the list!" << std::endl;
        return;
    }
    Node *temp = head;
    if (length == 1)
    {
        delete temp;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = temp->next;
        delete temp;
    }
    length--;
}

Node *LinkedList::getNodeByIndex(int index)
{
    if (index < 0 || index >= length)
    {
        std::cout << "Index out of range: " << std::endl;
        return nullptr;
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

Node *LinkedList::getNodeByValue(int value)
{
    for (int i = 0; i < length; i++)
    {
        Node *temp = getNodeByIndex(i);
        if (temp->value == value)
        {
            return temp;
        }
    }
    return nullptr;
}

bool LinkedList::deleteByIndex(int index)
{
    if (index < 0 || index >= length)
    {
        std::cout << "Index out of range" << std::endl;
        return false;
    }
    if (index == 0)
    {
        deleteFirst();
        return true;
    }
    if (index == length - 1)
    {
        deleteLast();
        return true;
    }
    Node *pre = getNodeByIndex(index - 1);
    if (pre)
    {
        Node *temp = pre->next;
        Node *after = temp->next;
        delete temp;
        length--;
        pre->next = after;
        return true;
    }
    return false;
}

bool LinkedList::deleteByValue(int value)
{
    Node *temp = head;
    if (temp == nullptr)
        return false;

    if (head->value == value)
    {
        deleteFirst();
        return true;
    }
    if (tail->value == value)
    {
        deleteLast();
        return true;
    }
    while (temp)
    {
        if (temp->value == value)
        {
            delete temp;
            length--;
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

bool LinkedList::deleteNthNodeFromEnd(int n)
{
    return deleteByIndex(length - n);
}

Node *LinkedList::getMiddleNode()
{
    return getNodeByIndex(length / 2);
}