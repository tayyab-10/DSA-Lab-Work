#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>
class AutoGrowingArray
{
private:
    T *autoarray;
    int size;
    int capacity;

public:
    AutoGrowingArray()
    {
        size = 0;
        capacity = 1;
        autoarray = new T[capacity];
    }

    void PushBack(T value)
    {
        if (size == capacity)
        {
            T *newArr = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = autoarray[i];
            }
            delete[] autoarray;
            autoarray = newArr;
            capacity *= 2;
        }
        autoarray[size++] = value;
    }

    void DisplayArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << autoarray[i] << " ";
        }
        cout << endl;
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

    void readRandomFile(string filename, AutoGrowingArray<T> &grow)
    {
        ifstream file(filename);
        T number;
        while (file >> number)
        {
            grow.PushBack(number);
        }
        file.close();
    }
};

int main()
{
    AutoGrowingArray<int> obj;
    obj.CreateRandomFile("OutputVector.txt", 2);
    cout << "Before Time: " << time(0) << endl;

    AutoGrowingArray<int> newArray;
    newArray.readRandomFile("OutputVector.txt", newArray);

    cout << "After Time: " << time(0) << endl;

    return 0;
}
