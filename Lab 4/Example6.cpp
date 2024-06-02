#include <iostream>
using namespace std;

void dec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    dec(n - 1);
}

void Inc(int n)
{
    if (n == 0)
    {
        return;
    }
    Inc(n - 1);
    cout << n << endl; // it will run when the base condition hits
}
int main()
{
    int n;
    cin >> n;
    dec(n);
    Inc(n);
    return 0;
}