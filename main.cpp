#include "LinkedList/LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList *list_1 = new LinkedList(4);
    list_1->append(5);
    list_1->prepend(3);
    list_1->insertAtIndex(1, 66);
    list_1->printList();
    list_1->reverse();
    list_1->printList();
    delete list_1;
    return 0;
}
