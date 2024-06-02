#include <iostream>
using namespace std;

int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + Sum(n / 3);
}
int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    cout << "The sum of the series is: " << Sum(n) << endl;

    return 0;
}