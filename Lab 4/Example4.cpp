#include <iostream>
using namespace std;

int Fibanocci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return Fibanocci(n - 1) + Fibanocci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << Fibanocci(n);
}