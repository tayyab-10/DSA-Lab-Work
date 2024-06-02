// Stack Problems

// Problem 1:

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

// Problem 2:

class MinStack
{
public:
    int size;
    int capacity;
    int *data;

    MinStack()
    {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    void push(int val)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *newData = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = val;
        size++;
    }

    void pop()
    {
        if (size > 0)
        {
            size--;
        }
    }

    int top()
    {
        if (size > 0)
        {
            return data[size - 1];
        }
        else
        {
            return -1;
        }
    }

    int getMin()
    {
        if (size > 0)
        {
            int minValue = data[0];
            for (int i = 1; i < size; i++)
            {
                if (data[i] < minValue)
                {
                    minValue = data[i];
                }
            }
            return minValue;
        }
        else
        {
            return -1;
        }
    }
};

// Problem 3:

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int leftMax = height[0], rightMax = height[right];
        int waterTrapped = 0;

        while (left < right)
        {
            if (height[left] <= height[right])
            {
                leftMax = max(leftMax, height[left]);
                waterTrapped += leftMax - height[left];
                left++;
            }
            else
            {
                rightMax = max(rightMax, height[right]);
                waterTrapped += rightMax - height[right];
                right--;
            }
        }

        return waterTrapped;
    }
};

// Problem 4:

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numberStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNumber = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (isdigit(c))
            {
                currentNumber = currentNumber * 10 + (c - '0');
            }
            else if (c == '[')
            {
                numberStack.push(currentNumber);
                stringStack.push(currentString);
                currentNumber = 0;
                currentString = "";
            }
            else if (c == ']')
            {
                int number = numberStack.top();
                numberStack.pop();
                string prevStr = stringStack.top();
                stringStack.pop();
                for (int i = 0; i < number; ++i)
                {
                    prevStr += currentString;
                }
                currentString = prevStr;
            }
            else
            {
                currentString += c;
            }
        }

        return currentString;
    }
};

// Problem 5:

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = heigh.sizet() - 1;
        int maxArea = 0;

        while (left < right)
        {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};

// Problem 6:

class MyStack
{
public:
    int size;
    int capacity;
    int *data;
    MyStack()
    {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }

    void push(int x)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *newData = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = x;
        size++;
    }

    int pop()
    {
        if (size > 0)
        {
            size--;
            return data[size];
        }
        return -1;
    }

    int top()
    {
        if (size > 0)
        {
            return data[size - 1];
        }
        else
        {
            return -1;
        }
    }

    bool empty()
    {
        return size == 0;
    }
};

// Problem 7:

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> StudentsQueue;

        for (int i = 0; i < students.size(); i++)
        {
            StudentsQueue.push(students[i]);
        }

        int topPositionOfSandwich = 0;
        int numStudentsUnableEat = 0;

        while (!StudentsQueue.empty() && numStudentsUnableEat < StudentsQueue.size())
        {
            if (sandwiches[topPositionOfSandwich] == StudentsQueue.front())
            {
                numStudentsUnableEat = 0;

                topPositionOfSandwich++;
                StudentsQueue.pop();
            }
            else
            {
                numStudentsUnableEat++;

                StudentsQueue.push(StudentsQueue.front());
                StudentsQueue.pop();
            }
        }

        return numStudentsUnableEat;
    }
};

// Problem 8:

class FrontMiddleBackQueue
{
    deque<int> frontBack;

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        frontBack.push_front(val);
    }

    void pushMiddle(int val)
    {
        int mid = frontBack.size() / 2;
        frontBack.insert(frontBack.begin() + mid, val);
    }

    void pushBack(int val)
    {

        frontBack.push_back(val);
    }

    int popFront()
    {
        if (!frontBack.empty())
        {
            int val = frontBack.front();
            frontBack.pop_front();
            return val;
        }
        return -1;
    }

    int popMiddle()
    {
        if (!frontBack.empty())
        {
            int mid = (frontBack.size() - 1) / 2;
            int element = *(frontBack.begin() + mid);
            frontBack.erase(frontBack.begin() + mid);
            return element;
        }
        return -1;
    }

    int popBack()
    {
        if (!frontBack.empty())
        {
            int val = frontBack.back();
            frontBack.pop_back();
            return val;
        }
        return -1;
    }
};

// Problem 9:

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currentMax = 0;
        int currentMin = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];

            currentMax = max(currentMax + nums[i], nums[i]);
            maxSum = max(maxSum, currentMax);

            currentMin = min(currentMin + nums[i], nums[i]);
            minSum = min(minSum, currentMin);
        }

        if (minSum == totalSum)
        {

            return maxSum;
        }
        else
        {

            return max(maxSum, totalSum - minSum);
        }
    }
};

// Problem 10:

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        deque<int> collided;
        for (int i = 0; i < asteroids.size(); i++)
        {
            bool flag = true;
            while (!collided.empty() && asteroids[i] < 0 && collided.back() > 0)
            {
                if (abs(collided.back()) < abs(asteroids[i]))
                {
                    collided.pop_back();
                    continue;
                }
                else if (abs(collided.back()) == abs(asteroids[i]))
                {
                    collided.pop_back();
                }
                flag = false;
                break;
            }
            if (flag)
            {
                collided.push_back(asteroids[i]);
            }
        }
        vector<int> result(collided.size());
        int size = collided.size() - 1;
        for (int i = 0; i <= size; i++)
        {
            result[i] = collided.front();
            collided.pop_front();
        }
        return result;
    }
};