#include <iostream>
using namespace std;

int TriSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n <= 3)
    {
        return n;
    }
    else
    {
        return TriSum(n - 1) + TriSum(n - 2) + TriSum(n - 3);
    }
}

int main()
{
    int number;
    cout << "Enter number to calculate the trisum of the series upto the number : " << endl;
    cin >> number;
    cout << TriSum(number);
}

// Iterative code :

// #include <iostream>
// using namespace std;

// int TriSum(int n)
// {
//     if (n <= 0)
//     {
//         return 0;
//     }
//     else if (n <= 3)
//     {
//         return n;
//     }
//     else
//     {
//         int first = 1, second = 2, third = 3, current;
//         for (int i = 4; i <= n; i++)
//         {
//             current = first + second + third;
//             first = second;
//             second = third;
//             third = current;
//         }
//         return current;
//     }
// }

// int main()
// {
//     int number;
//     cout << "Enter number to calculate the trisum of the series upto the number : " << endl;
//     cin >> number;
//     cout << TriSum(number);
// }