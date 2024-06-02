#include <iostream>
using namespace std;

int DecimalToBinary(int n)
{
    if (n == 0)
    {
        return 0;
    }
    float result = DecimalToBinary(n / 2) * 10;

    return result + n % 2;
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    cout << "The Desired Binary is : " << DecimalToBinary(n);
    return 0;
}