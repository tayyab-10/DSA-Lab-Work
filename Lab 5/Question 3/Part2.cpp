#include <iostream>
using namespace std;

int SearchLastEntry(int arr[], int size, int i, int key)
{
    if (i == size)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return SearchLastEntry(arr, size, i - 1, key);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int value = 6;

    int result = SearchLastEntry(arr, size, 5, value);

    if (result != -1)
    {
        cout << "The Last occurrence of " << value << " is at index " << result << endl;
    }
    else
    {
        cout << value << " not found in the array." << endl;
    }
    return 0;
}