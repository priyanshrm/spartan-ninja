#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

struct Node;
struct Node *createNode(int val);
void printDLL(struct Node **head);
void insert(struct Node **head, int val);
void delete(struct Node **head, int pos);

#endif