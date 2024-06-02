#include <iostream>
#include <stack>
using namespace std;

stack<int> sorted;

stack<int> Sortstack(stack<int> &vals)
{
    while (!vals.empty())
    {
        int temp = vals.top();
        vals.pop();

        while (!sorted.empty() && sorted.top() > temp)
        {
            vals.push(sorted.top());
            sorted.pop();
        }

        sorted.push(temp);
    }
    return sorted;
}

int main()
{
    stack<int> vals;
    vals.push(13);
    vals.push(11);
    vals.push(-4);
    vals.push(23);
    vals.push(-3);

    stack<int> st = Sortstack(vals);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
