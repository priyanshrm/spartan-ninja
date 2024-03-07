#include "../Node/Node.h"
#include <iostream>

Node::Node(int value)
{
    this->value = value;
    next = nullptr;
};

std::ostream &operator<<(std::ostream &os, const Node *node)
{
    if (node)
    {
        os << "(" << node->value << ") ->";
    }
    else
    {
        os << "nullptr";
    }
    return os;
};
