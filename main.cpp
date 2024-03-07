#include "LinkedList/LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList *list_1 = new LinkedList(4);
    list_1->printList();
    delete list_1;
    return 0;
}
