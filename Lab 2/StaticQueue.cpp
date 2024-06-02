#include <iostream>
using namespace std;

template <typename T>
class StaticQueue
{
    int size;
    int capacity;
    T *data;
    int Fi; // Front index
    int Ri; // Rear index
    int prev_r;

public:
    StaticQueue(int value)
    {
        size = 0;
        capacity = value;
        data = new T[capacity];
        Fi = Ri = 0;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    bool IsFull()
    {
        return size == capacity;
    }

    void push(T value)
    {
        if (IsFull())
        {
            cout << "The queue is already full" << endl;
        }
        else
        {
            data[Ri] = value;
            size++;
            prev_r = Ri;
            Ri = (Ri + 1) % capacity;
        }
    }

    // void PrintQueue()
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         cout << data[(Fi + i) % capacity] << " ";
    //     }
    //     cout << endl;
    // }

    void pop()
    {
        if (IsEmpty())
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            Fi = (Fi + 1) % capacity;
            size--;
        }
    }

    T Front()
    {
        if (IsEmpty())
        {
            cerr << "Error: Queue is empty" << endl;
            return T();
        }
        return data[Fi];
    }

    T Back()
    {
        if (IsEmpty())
        {
            cout << "The Queue is Empty:";
        }
        return data[prev_r];
    }
};

int main()
{
    StaticQueue<int> SQ(5);
    SQ.push(1);
    SQ.push(2);
    SQ.push(3);
    SQ.pop();
    cout << "Front: " << SQ.Front() << endl;
    cout << "Back: " << SQ.Back() << endl;

    // SQ.PrintQueue();

    return 0;
}
