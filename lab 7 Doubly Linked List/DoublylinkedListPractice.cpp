#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;
    Node *Prev;
    Node(int value)
    {
        data = value;
        Next = nullptr;
        Prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    class ForwardIterator
    {
    public:
        Node *current;

        ForwardIterator(Node *node)
        {
            current = node;
        }

        ForwardIterator &
        operator++()
        {
            if (current != nullptr)
            {
                current = current->Next;
            }
            return *this;
        }

        bool operator==(const ForwardIterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const ForwardIterator &other) const
        {
            return current != other.current;
        }

        int operator*() const
        {
            return current->data;
        }
    };

    ForwardIterator fbegin()
    {
        return ForwardIterator(head);
    }

    ForwardIterator fend()
    {
        return ForwardIterator(nullptr);
    }

    class ReverseIterator
    {
    public:
        Node *current;

        ReverseIterator(Node *node)
        {
            current = node;
        }

        ReverseIterator &operator++()
        {
            if (current != nullptr)
            {
                current = current->Prev;
            }
            return *this;
        }

        bool operator==(const ReverseIterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const ReverseIterator &other) const
        {
            return current != other.current;
        }

        int operator*() const
        {
            return current->data;
        }
    };

    ReverseIterator rbegin()
    {
        return ReverseIterator(tail);
    }

    ReverseIterator rend()
    {
        return ReverseIterator(nullptr);
    }

    class Iterator
    {
    public:
        Node *current;

        Iterator(Node *node)
        {
            current = node;
        }

        Iterator &operator++()
        {
            if (current != nullptr)
            {
                current = current->Next;
            }
            return *this;
        }

        Iterator &operator--()
        {
            if (current != nullptr)
            {
                current = current->Prev;
            }
            return *this;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }

        int operator*() const
        {
            return current->data;
        }
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
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
            tail->Next = new_Node;
            tail = new_Node;
        }
    }

    void InsertAtHead(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->Next = head;
            head->Prev = newNode;
            head = newNode;
        }
    }

    void InsertAtTail(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->Prev = tail;
            tail->Next = newNode;
            tail = newNode;
        }
    }

    void RemoveAtHead()
    {
        if (head != nullptr)
        {
            if (head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->Next;
                head->Prev = nullptr;
            }
        }
    }

    void RemoveAtTail()
    {
        if (tail != nullptr)
        {
            if (tail == head)
            {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = tail->Prev;
                tail->Next = nullptr;
            }
        }
    }

    void DeleteAtMiddle(int value)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->Next;
        }
        if (temp != nullptr)
        {
            if (temp->Prev != nullptr)
            {
                temp->Prev->Next = temp->Next;
            }
            if (temp->Next != nullptr)
            {
                temp->Next->Prev = temp->Prev;
            }
            delete temp;
        }
    }

    void DisplayList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->Next != nullptr)
            {
                cout << "->";
            }
            temp = temp->Next;
        }
        cout << endl;
    }

    void splice(Node *posiion, DoublyLinkedList &newList)
    {
        if (posiion == nullptr || newList.head == nullptr)
        {

            return;
        }

        newList.tail->Next = posiion->Next;
        posiion->Next = newList.head;
        newList.head->Prev = posiion;
    }
};

int main()
{
    DoublyLinkedList list1;
    DoublyLinkedList list2;

    list1.InsertElements(12);
    list1.InsertElements(11);
    list1.InsertElements(10);
    list1.InsertElements(32);

    list2.InsertElements(6);
    list2.InsertElements(5);
    list2.InsertElements(4);
    list2.InsertElements(3);
    list2.InsertElements(2);

    list1.splice(list1.head->Next, list2);
    list1.DisplayList();

    // Forward Iterator
    cout << "Forward Iterator: ";
    for (DoublyLinkedList::ForwardIterator i = list1.fbegin(); i != list1.fend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // Reverse Iterator
    cout << "Reverse Iterator: ";
    for (DoublyLinkedList::ReverseIterator i = list1.rbegin(); i != list1.rend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // General Iterator
    cout << "General Iterator: ";
    for (DoublyLinkedList::Iterator i = list1.begin(); i != list1.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}

// LeetCode Problems-------------------------

//    Question 2:

//     class Solution
//     {
//     public:
//         ListNode *removeNthFromEnd(ListNode *head, int n)
//         {

//             ListNode *temp = new ListNode();
//             temp->next = head;

//             ListNode *slow = temp;
//             ListNode *fast = temp;

//             while (n > 0)
//             {
//                 fast = fast->next;
//                 n--;
//             }

//             while (fast->next)
//             {
//                 fast = fast->next;
//                 slow = slow->next;
//             }

//             slow->next = slow->next->next;
//             slow = fast;

//             return temp->next;
//         }
//     };

//     // Question 3 :

//     class Solution
//     {
//     public:
//         ListNode *swapPairs(ListNode *head)
//         {
//             if (head == nullptr || head->next == nullptr)
//                 return head;

//             ListNode *prev = head;
//             ListNode *curr = head->next->next;
//             head = head->next;
//             head->next = prev;

//             while (curr != nullptr && curr->next != nullptr)
//             {

//                 prev->next = curr->next;
//                 prev = curr;
//                 ListNode *temp = curr->next->next;
//                 curr->next->next = curr;
//                 curr = temp;
//             }
//             prev->next = curr;
//             return head;
//         }
//     };

//     // Question 4 :

//     class Solution
//     {
//     public:
//         ListNode *reverseBetween(ListNode *head, int left, int right)
//         {
//             if (!head || left == right)
//             {
//                 return head;
//             }

//             ListNode *prev = head;
//             ListNode *current = head;

//             for (int i = 1; i < left; i++)
//             {
//                 prev = current;
//                 current = current->next;
//             }

//             ListNode *next = current->next;
//             ListNode *temp = next->next;

//             for (int i = 0; i <= right - left; i++)
//             {
//                 next->next = current;
//                 current = next;
//                 next = temp;
//                 temp = (next != nullptr) ? next->next : nullptr;
//             }

//             prev->next = next;
//             prev->next = current;
//             return head;
//         }
//     };

//     // Question 5 :

//     lass Node
//     {
//     public:
//         int data;
//         Node *next;
//         Node(int value) : data(value), next(nullptr) {}
//     };

//     class MyLinkedList
//     {
//     public:
//         Node *head;
//         int length;

//         MyLinkedList()
//         {
//             head = nullptr;
//             length = 0;
//         }

//         int get(int index)
//         {
//             if (index < 0 || index >= length)
//             {
//                 return -1;
//             }
//             Node *temp = head;
//             for (int i = 0; i < index; i++)
//             {
//                 temp = temp->next;
//             }
//             return temp->data;
//         }

//         void addAtHead(int val)
//         {
//             Node *newNode = new Node(val);
//             newNode->next = head;
//             head = newNode;
//             length++;
//         }

//         void addAtTail(int val)
//         {
//             Node *newNode = new Node(val);
//             if (!head)
//             {
//                 head = newNode;
//             }
//             else
//             {
//                 Node *temp = head;
//                 while (temp->next)
//                 {
//                     temp = temp->next;
//                 }
//                 temp->next = newNode;
//             }
//             length++;
//         }

//         void addAtIndex(int index, int val)
//         {
//             if (index < 0 || index > length)
//             {
//                 return;
//             }
//             if (index == 0)
//             {
//                 addAtHead(val);
//             }
//             else
//             {
//                 Node *newNode = new Node(val);
//                 Node *temp = head;
//                 for (int i = 0; i < index - 1; i++)
//                 {
//                     temp = temp->next;
//                 }
//                 newNode->next = temp->next;
//                 temp->next = newNode;
//                 length++;
//             }
//         }

//         void deleteAtIndex(int index)
//         {
//             if (index < 0 || index >= length)
//             {
//                 return;
//             }
//             if (index == 0)
//             {
//                 Node *temp = head;
//                 head = head->next;
//                 delete temp;
//                 length--;
//             }
//             else
//             {
//                 Node *temp = head;
//                 for (int i = 0; i < index - 1; i++)
//                 {
//                     temp = temp->next;
//                 }
//                 Node *toDelete = temp->next;
//                 temp->next = temp->next->next;
//                 delete toDelete;
//                 length--;
//             }
//         }
//     };
// };