#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<long long int> power;
int PowerSum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (power[n] != -1)
    {
        return power[n];
    }
    else
    {
        float result = PowerSum(n / 2);
        return n + result;
    }
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n < 0)
    {
        cout << "N should be a non-negative integer." << endl;
        return 1;
    }

    int result = PowerSum(n);
    cout << "The sum of the series is: " << result << endl;
    return 0;
}
