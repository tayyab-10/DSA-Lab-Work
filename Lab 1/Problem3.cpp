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
        capacity = 2;
        autoarray = new T[capacity];
    }

    void PushBack(T value)
    {
        if (size == capacity)
        {
            double newCapacity = capacity * 1.5;
            int newCapacityInt = static_cast<int>(newCapacity);
            T *newArr = new T[newCapacityInt];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = autoarray[i];
            }
            delete[] autoarray;
            autoarray = newArr;
            capacity = newCapacityInt;
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
    obj.CreateRandomFile("OutputArrayList.txt", 2);
    cout << "Before Time: " << time(0) << endl;

    AutoGrowingArray<int> growArr;
    growArr.readRandomFile("OutputArrayList.txt", growArr);

    cout << "After Time: " << time(0) << endl;

    return 0;
}
