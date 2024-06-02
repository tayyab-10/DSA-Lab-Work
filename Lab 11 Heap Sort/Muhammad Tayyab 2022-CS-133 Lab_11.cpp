#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

class Compare
{
public:
    bool operator()(const int &a, const int &b) const
    {
        return a >= b;
    }
};

template <class T>
void Heapsort(vector<T> &V, priority_queue<T, vector<T>, Compare> &maxHeap)
{
    // Create a max heap using the priority queue
    for (const T &element : V)
    {
        maxHeap.push(element);
    }

    // Extract elements from the max heap to sort the vector
    while (!maxHeap.empty())
    {
        V.push_back(maxHeap.top());
        maxHeap.pop();
    }
}
// Bubble Sort:
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort:
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        swap(arr[smallest], arr[i]);
    }
}

// Insertion Sort:
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

// Merge Sort:
void merge(vector<int> &arr, int si, int mid, int ei)
{
    int size = ei - si + 1;
    vector<int> mergedArray(size);

    int idx1 = si;
    int idx2 = mid + 1;
    int idx = 0;

    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            mergedArray[idx++] = arr[idx1++];
        }
        else
        {
            mergedArray[idx++] = arr[idx2++];
        }
    }

    while (idx1 <= mid)
    {
        mergedArray[idx++] = arr[idx1++];
    }

    while (idx2 <= ei)
    {
        mergedArray[idx++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < size; i++, j++)
    {
        arr[j] = mergedArray[i];
    }
}

void mergeSort(vector<int> &arr, int si, int ei)
{
    if (si < ei)
    {
        int mid = si + (ei - si) / 2;
        mergeSort(arr, si, mid);
        mergeSort(arr, mid + 1, ei);
        merge(arr, si, mid, ei);
    }
}

// Quick Sort:
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pidx = partition(arr, low, high);
        quickSort(arr, low, pidx - 1);
        quickSort(arr, pidx + 1, high);
    }
}

// Insertion Sort:
void insertionSort(vector<float> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        float current = arr[i];
        int j = i - 1;
        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void Randomized_Init(vector<int> &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        V[i] = rand() % 100;
    }
}

void Vector_Print(vector<int> &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << "->";
    }
    cout << endl
         << endl;
}

void CreateRandomFile(string Fn, int Size, int RN)
{
    srand(time(0));
    ofstream Writer(Fn);
    for (int i = 0; i < Size; i++)
    {
        Writer << rand() % RN << " ";
    }
    Writer.close();
}

void readRandomFile(string filename, vector<int> &V)
{
    ifstream file(filename);
    int number;
    while (file >> number)
    {
        V.push_back(number);
    }
    file.close();
}
int main()
{
    const string filename = "1GB_data.txt";
    const int fileSizeInMB = 1024; // 1GB = 1024MB
    const int maxValue = 100;

    // Create a random data file
    CreateRandomFile(filename, fileSizeInMB, maxValue);

    // Read data from the file into a vector
    vector<int> Values;
    readRandomFile(filename, Values);

    // Perform quickSort and measure time
    auto start = high_resolution_clock::now();

    // quickSort(Values, 0, Values.size() - 1);
    bubbleSort(Values);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Time taken by quickSort: " << duration.count() << " milliseconds" << endl;

    return 0;
}
