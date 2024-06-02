#include <iostream>

using namespace std;

void RecursiveSubarrays(int arr[], int start, int end)
{
    if (start > end)
    {
        return;
    }
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    RecursiveSubarrays(arr, start, end - 1);
    RecursiveSubarrays(arr, start + 1, end);
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "All possible subarrays of the given array are:" << endl;
    RecursiveSubarrays(arr, 0, n - 1);

    return 0;
}

// Iterative code :
// #include <iostream>

// using namespace std;

// // Function to generate all possible subarrays of the given array
// void generateSubarrays(int arr[], int n)
// {
//     // Outer loop to iterate through the starting index of subarray
//     for (int start = 0; start < n; start++)
//     {
//         // Inner loop to iterate through the ending index of subarray
//         for (int end = start; end < n; end++)
//         {
//             // Print the elements of the subarray from start to end
//             for (int i = start; i <= end; i++)
//             {
//                 cout << arr[i] << " ";
//             }
//             cout << endl;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "All possible subarrays of the given array are:" << endl;
//     generateSubarrays(arr, n);

//     return 0;
// }
