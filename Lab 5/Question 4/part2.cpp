#include <iostream>
using namespace std;

int PowMod(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        int temp = PowMod(x, y / 2, m);
        if (y % 2 == 0)
        {
            return (temp * temp) % m;
        }
        else
        {
            return ((x * temp * temp) % m);
        }
    }
}

int main()
{
    int x = 3;
    int y = 5;
    int m = 7;
    int result = PowMod(x, y, m);
    cout << "The Result of this expression is : " << result << endl;
    return 0;
}
