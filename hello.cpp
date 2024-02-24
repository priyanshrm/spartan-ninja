#include <iostream>

using namespace std;

int main()
{
    int *p = new int(11);
    int *q = p;

    cout << *p << " " << *q << endl;

    *p = 22;

    cout << *p << " " << *q << endl;

    return 0;
}