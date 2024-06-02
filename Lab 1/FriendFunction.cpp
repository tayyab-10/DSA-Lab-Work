#include <iostream>
using namespace std;

class MyClass
{
private:
    int privateMember;

public:
    MyClass(int value)
    {
        privateMember = value;
    }

    friend void friendFunction(const MyClass &obj);
};

void friendFunction(const MyClass &obj)
{

    int value = obj.privateMember;
    cout << value;
}

int main()
{
    MyClass obj(42);
    friendFunction(obj);
    return 0;
}
