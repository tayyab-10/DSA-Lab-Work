#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 4, 5, 2, 6, 5, 3};
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    int target;
    cin >> target;
    int left = 0;
    int right = arrsize - 1;
    int result = -1; // Initialize result to -1 (not found)

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid; // Update the result and continue searching for a better match
            break;        // Break out of the loop since we found the target
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Adjust the left bound
        }
        else
        {
            right = mid - 1; // Adjust the right bound
        }
    }

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
