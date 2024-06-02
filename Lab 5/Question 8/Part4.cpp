#include <iostream>
#include <vector>

using namespace std;

vector<long long int> Sum;

long long int TriSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n <= 3)
    {
        return n;
    }
    else if (Sum[n] != -1)
    {
        return Sum[n];
    }
    else
    {
        Sum[n] = TriSum(n - 1) + TriSum(n - 2) + TriSum(n - 3);
        return Sum[n];
    }
}

int main()
{

    int number;
    cout << "Enter number to calculate the trisum of the series upto the number : " << endl;
    cin >> number;

    Sum.assign(number + 1, -1);
    cout << TriSum(number);
}