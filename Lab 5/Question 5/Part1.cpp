#include <iostream>

using namespace std;

int Add(int x, int y)
{
    return x + y;
}

int Mult(int A, int B)
{
    int result = 0;

    while (B > 0)
    {
        if (B % 2 == 1)
        {
            result = Add(result, A);
        }
        A = A << 1;
        B = B >> 1;
    }

    return result;
}

int main()
{
    int A = 7;
    int B = 5;

    int product = Mult(A, B);

    cout << "Product: " << product << endl;

    return 0;
}
