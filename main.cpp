#include "LinkedList/LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Test creating an empty list and performing operations
    LinkedList emptyList;
    std::cout << "Testing operations on an empty list:\n";
    emptyList.printList();        // Should show nothing
    emptyList.deleteFirst();      // Should gracefully handle
    emptyList.deleteLast();       // Should gracefully handle
    emptyList.deleteByIndex(0);   // Should gracefully handle
    emptyList.deleteByValue(100); // Should not find anything
    // Node *emptySearch = emptyList.getNodeByIndex(0); // Should return nullptr
    // if (!emptySearch)
    // std::cout << "Empty search correctly returned nullptr.\n";

    // // Test appending to an empty list then more
    // std::cout << "\nTesting with single item list:\n";
    // emptyList.append(1);
    // emptyList.printList(); // Should show (1) ->
    // emptyList.append(2);   // Test appending to a list with one item
    // emptyList.printList(); // Should show (1) -> (2) ->

    // // Test prepending and inserting at boundaries
    // LinkedList list;
    // std::cout << "\nTesting prepending and inserting at boundaries:\n";
    // list.prepend(10);          // Prepend to empty list
    // list.printList();          // Should show (10) ->
    // list.insertAtIndex(0, 5);  // Insert at beginning
    // list.insertAtIndex(2, 15); // Insert at end which is equivalent to append
    // list.printList();          // Should show (5) -> (10) -> (15) ->

    // // Insert at invalid index
    // std::cout << "\nInserting at invalid index (should show error):\n";
    // list.insertAtIndex(100, 20); // Invalid index

    // // Test deleting from list with multiple items
    // std::cout << "\nTesting deletions:\n";
    // list.deleteFirst();
    // list.printList(); // Should remove first item: (10) -> (15) ->
    // list.deleteLast();
    // list.printList(); // Should remove last item: (10) ->
    // list.append(20);
    // list.append(30);
    // list.deleteByValue(20);
    // list.printList();      // Should remove 20: (10) -> (30) ->
    // list.deleteByIndex(1); // Remove last remaining element
    // list.printList();      // Should show (10) ->

    // // Edge cases for deleteNthNodeFromEnd and getMiddleNode
    // std::cout << "\nEdge cases for deleteNthNodeFromEnd and getMiddleNode:\n";
    // list.append(40);
    // list.append(50);
    // list.deleteNthNodeFromEnd(2); // Should remove 40: (10) -> (50) ->
    // list.printList();
    // Node *middleNode = list.getMiddleNode();
    // std::cout << "Middle node value (should be 10 or 50 depending on implementation): " << middleNode->value << std::endl;

    // // Test reverse on different list sizes
    // std::cout << "\nTesting reverse on different list sizes:\n";
    // LinkedList reverseTest;
    // reverseTest.reverse(); // Reverse empty list
    // reverseTest.append(100);
    // reverseTest.reverse();   // Reverse single element list
    // reverseTest.printList(); // Should show (100) ->
    // reverseTest.append(200);
    // reverseTest.reverse();   // Reverse two-element list
    // reverseTest.printList(); // Should show (200) -> (100) ->

    return 0;
}
