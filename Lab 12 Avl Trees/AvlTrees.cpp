#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *Left;
    Node *Right;
    int height;
    Node(int val)
    {
        data = val;
        Left = nullptr;
        Right = nullptr;
        height = 1;
    }
};

class Avl
{
public:
    Node *root;
    Avl()
    {
        root = nullptr;
    }

    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    void updateHeight(Node *node)
    {
        node->height = 1 + max(getHeight(node->Left), getHeight(node->Right));
    }
    Node *RightRotate(Node *temp)
    {
        Node *x = temp->Left;
        Node *T2 = x->Right;

        // Perform rotation
        x->Right = temp;
        temp->Left = T2;

        // Update heights
        updateHeight(temp);
        updateHeight(x);

        // Return new root
        return x;
    }

    Node *LeftRotate(Node *y)
    {
        Node *x = y->Left;
        Node *T2 = x->Right;
        // Perform rotation
        x->Left = y;
        y->Right = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        // Return new root
        return x;
    }
    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->Left) - getHeight(node->Right);
    }
    Node *Insert(Node *node, int value)
    {

        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->Left = Insert(node->Left, value);
        else if (value > node->data)
            node->Right = Insert(node->Right, value);
        else
            return node;

        updateHeight(node);

        int balance = getBalance(node);

        // Left Left Rotation:
        if (balance > 1 && value < node->Left->data)
            return RightRotate(node);

        // Right Right Rotation :
        if (balance < -1 && value > node->Right->data)
            return LeftRotate(node);

        // Left Right Rotation:
        if (balance > 1 && value > node->Left->data)
        {
            node->Left = LeftRotate(node->Left);
            return RightRotate(node);
        }

        // Right Left Rotation:

        if (balance < -1 && value < node->Right->data)
        {
            node->Right = RightRotate(node->Right);
            return LeftRotate(node);
        }

        return node;
    }

    void PrintTree(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << "-> ";
            PrintTree(root->Left);
            PrintTree(root->Right);
        }
    }

    void InorderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        InorderTraversal(root->Left);
        cout << root->data << " ";
        InorderTraversal(root->Right);
    }
    bool isAVLTree(Node *node)
    {
        if (node == nullptr)
            return true;

        int balance = getBalance(node);

        if (abs(balance) > 1)
            return false;

        return isAVLTree(node->Left) && isAVLTree(node->Right);
    }
    Node *Delete(Node *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // Find the node to be deleted
        if (val < root->data)
        {
            root->Left = Delete(root->Left, val);
        }
        else if (val > root->data)
        {
            root->Right = Delete(root->Right, val);
        }
        else
        {
            // Case 1:
            if (root->Left == nullptr && root->Right == nullptr)
            {
                return nullptr;
            }

            // Node with only one child or no child
            if (root->Left == nullptr) // This means we traverse the whole tree
            {
                Node *temp = root->Right;
                delete root;
                return temp;
            }
            else if (root->Right == nullptr)
            {
                Node *temp = root->Left;
                delete root;
                return temp;
            }

            // Node with two children, get the inorder successor
            Node *IS = InorderSuccessor(root->Right);
            root->data = IS->data;

            // Delete the inorder successor
            root->Right = Delete(root->Right, IS->data);
        }

        return root;
    }

    Node *InorderSuccessor(Node *root)
    {
        while (root->Left != nullptr)
        {
            root = root->Left;
        }
        return root;
    }
    int HeightOfTree(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int heightLeft = HeightOfTree(root->Left);
        int heightRight = HeightOfTree(root->Right);
        return 1 + max(heightLeft, heightRight);
    }
};

int main()
{
    Avl obj;

    int arratemp1[] = {5, 4, 3, 6, 2};
    int size1 = sizeof(arratemp1) / sizeof(arratemp1[0]);

    for (int i = 0; i < size1; i++)
    {
        obj.root = obj.Insert(obj.root, arratemp1[i]);
    }
    obj.InorderTraversal(obj.root);
    // Check if the tree is an AVL tree
    if (obj.isAVLTree(obj.root))
    {
        cout << "The tree is an AVL tree." << endl;
    }
    else
    {
        cout << "The tree is not an AVL tree." << endl;
    }
    return 0;
}

// LeetCode Problems ::
// Problem 1:
/*class Solution
{
public:
    int GetHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int HeightLeft = GetHeight(root->left);
        int HeightRight = GetHeight(root->right);
        return 1 + max(HeightLeft, HeightRight);
    }

    void updateHeight(TreeNode *node)
    {
        node->val = 1 + max(GetHeight(node->left), GetHeight(node->right));
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        int bf = GetHeight(root->left) - GetHeight(root->right);

        if (bf > 1 && root->val < root->left->val)
            return RR_Rotations(root);
        // Right Right Rotation :
        if (bf < -1 && root->val > root->right->val)
            return LL_Rotation(root);
        // Left Right Rotation
        if (bf > 1 && root->val > root->left->val)
        {
            root->left = LL_Rotation(root->left);
            return RR_Rotations(root);
        }
        // Right Left Rotation
        if (bf < -1 && root->val < root->right->val)
        {
            root->right = RR_Rotations(root->right);
            return LL_Rotation(root);
        }

        return root;
    }

    TreeNode *RR_Rotations(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *t2 = x->right;

        x->right = y;
        y->left = t2;

        updateHeight(y);
        updateHeight(x);
        return x;
    }

    TreeNode *LL_Rotation(TreeNode *y)
    {
        TreeNode *x = y->right;
        TreeNode *t2 = x->left;

        x->left = y;
        y->right = t2;

    updateHeight(y);
       updateHeight(x);

  return x;
         }
};
 Problem 2 :

 class Solution {
public:

 int Height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int heightLeft = Height(root->left);
        int heightRight = Height(root->right);
        return 1 + max(heightLeft, heightRight);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int bf= Height(root->left)-Height(root->right);
        if(bf<-1 || bf>1){
            return false;
        }
  return isBalanced(root->left) && isBalanced(root->right);
    }
};*/
