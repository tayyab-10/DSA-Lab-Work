#include <iostream>

#include <vector>

using namespace std;

vector<long long int> memo;

long long int Fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else if (memo[n] != -1)
    {
        return memo[n];
    }
    else
    {
        memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        return memo[n];
    }
}

int main()
{
    int n;
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;

    memo.assign(n + 1, -1);

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << Fibonacci(i);
    }

    cout << endl;

    return 0;
}
