#include <iostream>
using namespace std;

template <typename T>
class DynamicQueue
{
    int size;
    int capacity;
    T *data;
    int Fi;
    int Ri;
    int prev_r;

public:
    DynamicQueue()
    {
        size = 0;
        capacity = 1;
        data = new T[capacity];
        Fi = Ri = prev_r = 0;
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
            T *newData = new T[capacity *= 2];
            for (int i = 0, c = Fi; i < size; i++)
            {
                if (c == capacity)
                {
                    c = 0;
                }
                c++;

                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
            Fi = 0;
            Ri = size;
        }

        data[Ri] = value;
        size++;
        prev_r = Ri;
        Ri = (Ri + 1) % capacity;
    }

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
            cout << "Error: Queue is empty" << endl;
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
    DynamicQueue<int> SQ;
    SQ.push(1);
    SQ.push(2);
    SQ.push(3);
    SQ.pop();
    cout << "Front: " << SQ.Front() << endl;
    cout << "Back: " << SQ.Back() << endl;

    return 0;
}
