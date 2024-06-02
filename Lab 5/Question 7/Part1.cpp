// #include <iostream>
// using namespace std;

// int FibSum(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }

//     return FibSum(n - 1) + FibSum(n - 2);
// }

// int main()
// {
//     int number;
//     cout << "Enter Number of terms in the Fibnacci sequence : " << endl;
//     cin >> number;
//     for (int i = 0; i < number; ++i)
//     {

//         cout << FibSum(i) << " , ";
//     }
//     return 0;
// }

// iterative code :

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;

    long long int first = 0, second = 1;

    cout << "Fibonacci sequence: ";

    if (n >= 1)
    {
        cout << first;
    }

    for (int i = 1; i < n; ++i)
    {
        cout << ", " << second;
        long long int next = first + second;
        first = second;
        second = next;
    }

    cout << endl;

    return 0;
}
