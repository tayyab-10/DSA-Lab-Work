#include <iostream>
using namespace std;

int CalPower(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }
    return (x * y / 2) % m;
}

int main()
{
    int x;
    int y;
    int m;
    cout << "ENter the values of X , Y and M : " << endl;
    cin >> x;
    cin >> y;
    cin >> m;
    cout << CalPower(x, y, m);
}