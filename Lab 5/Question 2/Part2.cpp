#include <iostream>
#include <string>

using namespace std;

string Integer2String(int n)
{

    if (n >= 0 && n <= 9)
    {
        return to_string(n);
    }

    string lastDigit = to_string(n % 10);
    string remainingDigits = Integer2String(n / 10);

    return remainingDigits + lastDigit;
}

int main()
{
    int number;
    cout << "Enter the Integer number : " << endl;
    cin >> number;
    cout << "The converted string is : " << Integer2String(number);

    return 0;
}
