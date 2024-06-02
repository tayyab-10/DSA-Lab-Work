
        if (balance > 1 && value > node->Left->data)
        {
            node->Left = leftRotate(node->Left);
            return rightRotate(node);
        }
        // Right Left Rotation