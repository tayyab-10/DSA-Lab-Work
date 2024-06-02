#include <iostream>

using namespace std;

int generateSequence(int n)
{
    if (n <= 3)
    {
        return n;
    }
    else
    {
        return generateSequence(n - 1) + generateSequence(n - 2) + generateSequence(n - 3);
    }
}

int main()
{
    int number;
    cout << "Enter the Limit of the sequence : " << endl;
    cin >> number;
    for (int i = 1; i <= number; i++)    
    {
        cout << generateSequence(i) << " ";
    }
    cout << endl;

    return 0;
}
