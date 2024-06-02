#include <iostream>

using namespace std;

int Sum(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int preSum = Sum(n - 2);
    return n + preSum;
}

int main()
{
    int n;
    cin >> n;
    cout << Sum(n);
    return 0;
}