#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    };

    friend ostream &operator<<(ostream &os, const Node *node)
    {
        if (node != nullptr)
            os << "(" << node->value << ") -> ";
        else
            os << "nullptr";
        return os;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    };

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    };

    void printHeadValue()
    {
        if (head)
        {
            cout << head->value << "\n";
            return;
        }
        cout << "nullptr" << endl;
    }

    void printTailValue()
    {
        if (tail)
        {
            cout << tail->value << "\n";
            return;
        }
        cout << "nullptr" << endl;
    }

    void printLength()
    {
        cout << length << endl;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (length == 0)
            tail = newNode;
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = temp->next;
        }
        delete temp;
        length--;
    }

    Node *getByIndex(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Index out of range" << endl;
            return nullptr;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool setByIndex(int index, int value)
    {
        Node *temp = getByIndex(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
            return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = getByIndex(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteByIndex(int index)
    {
        if (index < 0 || index >= length)
            return;
        if (index == 0)
            return deleteFirst();
        if (index == length - 1)
            return deleteLast();
        Node *pre = getByIndex(index - 1);
        Node *temp = pre->next;
        pre->next = temp->next;
        length--;
        delete temp;
    }

    void printList()
    {
        for (int i = 0; i < length; i++)
            cout << getByIndex(i);
        cout << endl;
    }

    void reverseList()
    {
        Node *temp = head;
        head = tail;
        tail = temp;
        Node *before = nullptr;
        Node *after = temp->next;
        for (int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
        before = nullptr;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList *linkedlist_1 = new LinkedList(1);
    linkedlist_1->append(2);
    linkedlist_1->append(3);
    linkedlist_1->append(4);

    linkedlist_1->printList();
    linkedlist_1->reverseList();
    linkedlist_1->printList();

    delete linkedlist_1;

    return 0;
}
