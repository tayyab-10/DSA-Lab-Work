#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter number 1 : " << endl;
    cin >> num1;
    cout << "Enter number 2 : " << endl;
    cin >> num2;

    int gcd; // Variable to store the GCD

    // Find the minimum of num1 and num2
    int minNum = (num1 < num2) ? num1 : num2;

    for (int i = 1; i <= minNum; ++i)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i; // Update the GCD whenever a common divisor is found
        }
    }

    cout << "The GCD is " << gcd << endl;

    return 0;
}
