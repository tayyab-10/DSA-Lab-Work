#include <iostream>
using namespace std;

int Power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    int prePower = Power(n, p - 1);
    return n + prePower;
}
int main()
{
    int n, p;
    cin >> n;
    cin >> p;
    cout << Power(n, p);
    return 0;
}