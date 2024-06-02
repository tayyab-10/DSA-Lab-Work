#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{

public:
    Node *root;
    BinaryTree()
    {
        root = nullptr;
    }

    int idx = -1;
    Node *BuildBinaryTree(int array[], int size)
    {
        idx++;
        if (idx >= size || array[idx] == -1)
        {
            return nullptr;
        }
        Node *newNode = new Node(array[idx]);
        newNode->left = BuildBinaryTree(array, size);
        newNode->right = BuildBinaryTree(array, size);
        return newNode;
    }

    void Insert(int array[], int size)
    {
        root = BuildBinaryTree(array, size);
    }

    void InorderTraversal(Node *current)
    {
        if (current != nullptr)
        {
            InorderTraversal(current->left);
            cout << current->data << " ";
            InorderTraversal(current->right);
        }
    }

    void InorderTraversal()
    {
        InorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    int array1[] = {5, 4, 3, -1, -1, 6, 2}; // Note: Use -1 to represent a null node

    int size1 = sizeof(array1) / sizeof(array1[0]);
    BinaryTree obj1;
    obj1.Insert(array1, size1);

    cout << "Inorder Traversal: ";
    obj1.InorderTraversal();

    return 0;
}
