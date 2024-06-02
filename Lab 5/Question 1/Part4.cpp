#include <iostream>
#include <cmath>

using namespace std;

int PowerSum(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n + PowerSum(n / 3);
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n < 0)
    {
        cout << "N should be a non-negative integer." << endl;
        return 1;
    }

    int result = PowerSum(n);
    cout << "The sum of the series is: " << result << endl;
    return 0;
}
