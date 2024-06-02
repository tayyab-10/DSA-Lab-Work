#include <iostream>

using namespace std;

int BinarySearch(int arr[], int left, int key, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return BinarySearch(arr, mid + 1, right, key);
        }
        else
        {
            return BinarySearch(arr, mid - 1, left, key);
        }
        return -1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target element: ";
    cin >> target;

    int result = BinarySearch(arr, 0, size - 1, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}