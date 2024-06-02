#include <iostream>
#include <vector>
#include <queue>
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

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }
    Node *Insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = Insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = Insert(node->right, value);
        }

        return node;
    }

    int idx = -1;
    Node *BuildbinaryTree(int array[])
    {
        idx++;
        if (array[idx] == -1)
        {
            return nullptr;
        }
        Node *newnode = new Node(array[idx]);
        newnode->left = BuildbinaryTree(array);
        newnode->right = BuildbinaryTree(array);
        return newnode;
    }
    void InorderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }

    Node *SearchInBST(Node *node, int value)
    {
        if (node == nullptr)
        {
            return;
        }
        if (value == node->data)
        {
            return node;
        }
        if (value < node->data)
        {
            return SearchInBST(node->left, value);
        }
        if (value > node->data)
        {
            return SearchInBST(node->right, value)
        }
        return node;
    }
    Node *Delete(Node *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (val < root->data)
        {
            root->left = delete (root->left, val);
        }
        else if (val > root->data)
        {
            root->right = delete (root->right, val);
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *Is = InorderSuccessor(root->right);
            root->data = Is->data;

            root->right = Delete(root->right, Is->data);
        }
    }

    Node *InorderSuccessor(Node *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }
    void PrintBST(Node *root)
    {
        // iterative version of the code :

        // if (root == nullptr)
        // {
        //     cout << "Tree is empty." << endl;
        //     return;
        // }

        // vector<Node *> nodesVector;
        // nodesVector.push_back(root);

        // while (!nodesVector.empty())
        // {
        //     Node *current = nodesVector.front();
        //     nodesVector.erase(nodesVector.begin());

        //     cout << current->data << " ";

        //     if (current->left != nullptr)
        //         nodesVector.push_back(current->left);

        //     if (current->right != nullptr)
        //         nodesVector.push_back(current->right);
        // }

        // Recursive Version of this function :

        if (root != nullptr)
        {

            cout << root->data << " ";
            PrintBST(root->left);
            PrintBST(root->right);
        }
    }
    Node *StartNodeOfBST()
    {
        if (root != nullptr)
        {
            cout << root->data;
        }
    }
    void EndNodeOfBST(Node *root)
    {

        // Iterative version of the function :

        // if (root == nullptr)
        // {
        //     cout << "Tree is empty." << endl;
        //     return;
        // }

        // Node *temp = root;
        // while (temp->left != nullptr || temp->right != nullptr)
        // {
        //     if (temp->left != nullptr)
        //         temp = temp->left;
        //     else
        //         temp = temp->right;
        // }

        // cout << temp->data << endl;

        // Recursive Approach to this function :

        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            cout << "End node: " << root->data << endl;
            return;
        }

        // if (root->left != nullptr)
        //     EndNodeOfBST(root->left);

        // if (root->right != nullptr)
        //     EndNodeOfBST(root->right);
    }

    bool IdenticalTrees(int array1[], int array2[], int size1, int size2)
    {
        if (size1 != size2)
        {
            return false;
        }
        for (int i = 0; i < size1; i++)
        {
            if (array1[i] != array2[i])
            {
                return false;
            }
        }
        return true;
    }
    int HeightOfBST(Node *root)
    {

        // Iterative Approach to this function :

        //     if (root == nullptr)
        //     {
        //         cout << "Height of BST: 0" << endl;
        //         return;
        //     }

        //     int height = 0;

        //     // Traverse the tree level by level using a queue
        //     queue<Node *> nodesQueue;
        //     nodesQueue.push(root);

        //     while (!nodesQueue.empty())
        //     {
        //         int levelSize = nodesQueue.size();

        //         for (int i = 0; i < levelSize; ++i)
        //         {
        //             Node *current = nodesQueue.front();
        //             nodesQueue.pop();

        //             if (current->left != nullptr)
        //             {
        //                 nodesQueue.push(current->left);
        //             }
        //             if (current->right != nullptr)
        //             {
        //                 nodesQueue.push(current->right);
        //             }
        //         }

        //         // Increment the height after processing each level
        //         height++;
        //     }

        //     cout << "Height of BST: " << height << endl;
        // }

        // Recursuive Approach :
        if (root == nullptr)
        {
            return 0;
        }
        int heightleft = HeightOfBST(root->left);
        int heightright = HeightOfBST(root->right);
        return 1 + max(heightleft, heightright);
    }
    int countEvenNumbers(Node *root)
    {

        if (root == nullptr)
        {
            return 0;
        }

        int currentNodeCount = (root->data % 2 == 0) ? 1 : 0;

        int leftCount = countEvenNumbers(root->left);
        int rightCount = countEvenNumbers(root->right);

        return currentNodeCount + leftCount + rightCount;
    }
    bool ValidateBST(Node *temp, int &prevValue)
    {
        if (temp == nullptr)
        {
            return true;
        }

        if (!ValidateBST(temp->left, prevValue))
        {
            return false;
        }

        if (temp->data <= prevValue)
        {
            return false;
        }

        prevValue = temp->data;

        return ValidateBST(temp->right, prevValue);
    }

    bool isBST()
    {
        int prevValue = -190;
        return ValidateBST(root, prevValue);
    }
    int LeavesCount(Node *root)
    {

        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr || root->right == nullptr)
        {
            return 1;
        }

        int leftcount = LeavesCount(root->left);

        int rightcount = LeavesCount(root->right);

        return leftcount + rightcount;
    }
    int INternalNodes(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right != nullptr || root->right == nullptr && root->left != nullptr)
        {
            return 1;
        }
        int leftNodes = INternalNodes(root->left);
        int rightNodes = INternalNodes(root->right);
        return leftNodes + rightNodes;
    }
};
// if (root->left || root->right == nullptr)
// {
//     return nullptr;
// }
// cout << EndNodeOfBST(root->left);
// cout << EndNodeOfBST(root->right);

int main()
{
    int array1[] = {5, 4, 3, 6, 2};
    // int array2[] = {5, 4, 3, 6, 2};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    // int size2 = sizeof(array2) / sizeof(array2[0]);

    BST obj1;

    for (int i = 0; i < size1; i++)
    {
        obj1.root = obj1.Insert(obj1.root, array1[i]);
    }
    // for (int i = 0; i < size2; i++)
    // {
    //     obj1.root = obj1.Insert(obj1.root, array2[i]);
    // }

    obj1.EndNodeOfBST(obj1.root);
    // if (obj1.IdenticalTrees(array1, array2, size1, size2))
    // {
    //     cout << "Identical Trees" << endl;
    // }
    // else
    // {
    //     cout << "Not Identical Trees" << endl;
    // }
    cout << obj1.HeightOfBST(obj1.root) << endl;
    int result = obj1.LeavesCount(obj1.root);
    cout << "The Number of leaves nodes in Your BST Is : " << result;
    obj1.InorderTraversal(obj1.root);

    // int todelete = 4;
    // obj1.root = obj1.Delete(obj1.root, todelete); // Update obj1.root after deletion
    // obj1.PrintBST(obj1.root);
    // obj1.StartNodeOfBST();
    return 0;
}

// int valueToSearch = 4;

// if (obj1.SearchInBST(obj1.root, valueToSearch))
// {
//     cout << "found";
// }
// else
// {
//     cout << "not Found";
// }
