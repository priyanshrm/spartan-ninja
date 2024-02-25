#include <iostream>

using namespace std;

class Cookie
{
private:
    string color;

public:
    Cookie(string color)
    {
        this->color = color;
    };
    string getColor()
    {
        return this->color;
    };
    void setColor(string color)
    {
        this->color = color;
    };
};

int main()
{
    Cookie *cookie_1 = new Cookie("green");
    Cookie *cookie_2 = new Cookie("blue");

    cout << cookie_1->getColor() << endl;
    cout << cookie_2->getColor() << endl;

    return 0;
}