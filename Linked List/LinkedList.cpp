#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
template <typename T>

class LinkedList
{
public:
    Node *head;
    Node *tail;

    int size = 0;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void isEmpty()
    {
        if (head == nullptr)
        {
            cout << "Your linked list is empty right now push some element in it: ";
        }
    }
    void insertInMiddle(int value)
    {
        Node *slow = head;
        Node *fast = head;
        Node *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *newNode = new Node(value);

        newNode->next = slow;

        if (prev != nullptr)
        {
            prev->next = newNode;
        }
        else
        {

            head = newNode;
        }
    }

    void insertAfterValue(int value, int key)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                Node *new_Node = new Node(key);
                new_Node->next = temp->next;
                temp->next = new_Node;
                return;
                // NewNode = temp;
            }
            temp = temp->next;
            // pre = pre->next;
        }
    }

    void InsertBeforeKey(int value, int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->next->data == value)
            {
                Node *newNode = new Node(key);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }
    int InsertElements(int val)
    {
        Node *new_Node = new Node(val);

        if (head == nullptr)
        {
            head = new_Node;
            tail = new_Node;
        }
        else
        {
            tail->next = new_Node;
            tail = new_Node;
        }
    }

    int InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    int search(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data = val)
            {
                return temp->data;
            }
            temp = temp->next;
        }
    }
    T getFront()
    {
        Node *temp = head;
        return temp->data;
    }
    T getTail()
    {
        Node *temp = tail;
        while (temp->next == nullptr)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    void DeleteAtHead()
    {
        head = head->next;
    }
    void DeleteAtTail()
    {
        if (head->next == nullptr)
        {
            head = nullptr;
            return;
        }
        Node *SecondL = head;
        Node *Last = head->next;
        while (Last->next != nullptr)
        {
            Last = Last->next;
            SecondL = SecondL->next;
        }
        SecondL->next = nullptr;
    }

    void DeleteatAnyPosition(int value)
    {
        Node *temp = head;
        while (temp->next->data != value)
        {
            temp = temp->next;
        }
        Node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
    int SizeofList()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void DisplayList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        return;
    }

    void DisplayRecursively(Node *head)
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            return;
        }
        cout << temp->data << "->";
        DisplayRecursively(temp->next);
    }

    // Question 3 ::

    // Check the circular linked list :

    // bool CircularList()
    // {
    //     if (tail->next->data == head)
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    // Reversing the linked list  ::

    void PrintReversedList()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *pre = head;
        Node *current = head->next;
        while (current != nullptr)
        {
            Node *next = current->next;
            current->next = pre;

            pre = current;
            current = next;
        }
        head->next = nullptr;
        head = pre;
    }

    Node *ReverseRecursively(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *newHead = ReverseRecursively(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    void MiddleElement()
    {
        Node *slow = head;
        Node *fast = head;
        Node *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre != nullptr)
        {
            cout << pre->next->data;
        }
    }
};

// Question 2 Implement stack using linked list data strcuture :

//     template <typename T>
//     class Stack
// {
// public:
//     Node *top;
//     stack()
//     {
//         top = nullptr;
//     }

//     void push(T value)
//     {
//         Node *NewNode = new Node(value);
//         NewNode->next = top;
//         top = NewNode;
//     }
//     void pop()
//     {
//         top = top->next;
//     }

//     bool ISEMPTy()
//     {
//         if (top == nullptr)
//         {
//             return true;
//         }
//         return false;
//     }
// };
// Implement Queue using linked list data strcture :

// template <typename T>
// class Queue
// {
// public:
//     Node *top;
//     Node *bottom;

//     void push(T value)
//     {
//         Node *new_Node = new Node(value);

//         if (top == nullptr)
//         {
//             top = new_Node;
//             bottom = new_Node;
//         }
//         else
//         {
//             bottom->next = new_Node;
//             bottom = new_Node;
//         }
//     }

//     void DisplayTop()
//     {
//         if (top != nullptr)
//         {
//             cout << top->data;
//         }
//         else
//         {
//             cout << "Your Queue is empty right now please insert some elements in it  !! ";
//         }
//     }
//     void pop()
//     {
//         if (!isEmpty())
//         {
//             top = top->next;
//         }
//         else
//         {
//             cout << "Queue is empty. Cannot pop." << endl;
//         }
//     }
//     bool isEmpty()
//     {
//         if (top == nullptr)
//         {
//             return true;
//         }
//         return false;
//     }
// };

int main()
{
    LinkedList<int> List;
    List.InsertElements(1);
    List.InsertElements(2);
    List.InsertElements(3);
    List.InsertElements(4);
    // List.DeleteatAnyPosition(3);
    List.DisplayList();
    // List.InsertElements(5);
    // List.DisplayList();
    // cout << endl;
    // List.head = List.ReverseRecursively(List.head);
    // cout << endl;
    // List.DisplayList();
    // List.PrintReversedList();
    // List.DisplayListRecursively();
    // List.MiddleElement();
    // List.PrintReversed();

    return 0;
}