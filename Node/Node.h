#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
public:
    int value;
    Node *next;
    Node(int value);
    friend std::ostream &operator<<(std::ostream &os, const Node *node);
};

#endif
