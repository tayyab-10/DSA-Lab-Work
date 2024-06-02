#include <iostream>
using namespace std;

long long int Fibonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    long long int first = 0;
    long long int second = 1;
    long long int result = 0;

    for (int i = 2; i <= n; ++i)
    {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cout << Fibonacci(i) << " ,";
    }

    return 0;
}
