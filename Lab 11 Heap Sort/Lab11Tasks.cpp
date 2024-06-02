#include <queue>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Compare
{
public:
    bool operator()(const int &a, const int &b) const // operator () overloader
    {
        return a >= b;
    }
};
template <class T>
void Heapsort(vector<T> &V)
{
    // Create a max heap using the priority queue
    priority_queue<int> maxHeap;
    for (const T &element : V)
    {
        maxHeap.push(element);
    }

    // Extract elements from the max heap to sort the vector
    // for (int i = V.size() - 1; i >= 0; i--)
    // {
    //     V[i] = maxHeap.top();
    //     maxHeap.pop();
    // }
    while (!maxHeap.empty())
    {
        V.push_back(maxHeap.top());
        maxHeap.pop();
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

void CreateRandomFile(string Fn, int Size, int RN = 100)
{
    srand(time(0));
    ofstream Writer(Fn);
    for (int i = 0; i < Size * 1024 * 1024; i++)
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
    // vector<int> Values(5);
    // Randomized_Init(Values);
    // cout << "Before Sorting the Vector is : " << endl;
    // Vector_Print(Values);
    // Heapsort(Values);
    // cout << "After Sorting the Vector Becomes : " << endl;
    // Vector_Print(Values);
    return 0;
}

// priority_queue<int, vector<int>, Compare> PQ;
// PQ.push(20);
// PQ.push(30);
// PQ.push(40);
// PQ.push(10);
// PQ.push(5);
// while (!PQ.empty())
// {
//     cout << PQ.top() << "->";
//     PQ.pop();
// }
