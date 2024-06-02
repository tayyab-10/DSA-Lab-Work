#include <iostream>
using namespace std;

int Sum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + Sum(n / 2);
}
int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    cout << "The sum of the series is: " << Sum(n) << endl;

    return 0;
}