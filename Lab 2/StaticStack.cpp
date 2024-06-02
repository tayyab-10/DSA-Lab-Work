#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
    T *data;
    int size;
    int capacity;

public:
    Stack()
    {
        size = 0;
        capacity = 1;
        data = new T[capacity];
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

            capacity *= 2;
            T *newData = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        data[size] = value;
        size++;
    }
    void pop()
    {
        if (IsEmpty())
        {
            cout << "Your Stack is Empty";
        }
        else
        {
            size--;
        }
    }
    void PrintArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int top()
    {
        if (IsEmpty())
        {
            cout << "Your Stack is full";
        }
        else
        {
            return data[size - 1];
        }
    }
};

int main()
{
    Stack<int> S1;

    S1.push(1);
    S1.push(2);
    S1.push(13);
    S1.push(11);
    S1.PrintArray();
    S1.pop();
    cout << S1.top();
    // S1.PrintArray();
    return 0;
}
