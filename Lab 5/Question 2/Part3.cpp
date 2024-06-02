#include <iostream>
using namespace std;

int GCD(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }

    return GCD(num2, num1 % num2);
}

int main()
{
    int num1, num2;
    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;

    cout << "The GCD of " << num1 << " and " << num2 << " is " << GCD(num1, num2) << endl;

    return 0;
}
