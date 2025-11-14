#include <iostream>
using namespace std;

struct AVLNode
{
    int productID;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int val) : productID(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(AVLNode *node)
{
    return node ? node->height : 0;
}

int getBalance(AVLNode *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

AVLNode *minValueNode(AVLNode *node)
{
    AVLNode *current = node;
    while (current->left)
        current = current->left;
    return current;
}

AVLNode *deleteNode(AVLNode *root, int key)
{
    if (!root)
        return root;

    if (key < root->productID)
        root->left = deleteNode(root->left, key);
    else if (key > root->productID)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            AVLNode *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            AVLNode *temp = minValueNode(root->right);
            root->productID = temp->productID;
            root->right = deleteNode(root->right, temp->productID);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(AVLNode *node)
{
    if (node)
    {
        cout << node->productID << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void printBalanceFactors(AVLNode *node)
{
    if (node)
    {
        cout << "Node " << node->productID << " Balance Factor: " << getBalance(node) << endl;
        printBalanceFactors(node->left);
        printBalanceFactors(node->right);
    }
}

AVLNode *insert(AVLNode *node, int key)
{
    if (!node)
        return new AVLNode(key);

    if (key < node->productID)
        node->left = insert(node->left, key);
    else if (key > node->productID)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->productID)
        return rightRotate(node);
    if (balance < -1 && key > node->right->productID)
        return leftRotate(node);
    if (balance > 1 && key > node->left->productID)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->productID)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main()
{
    AVLNode *root = nullptr;
    int initial[] = {100, 80, 120, 70, 90, 110, 130};
    int n = sizeof(initial) / sizeof(initial[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, initial[i]);

    cout << "Pre-Order before deleting 80: ";
    preOrder(root);
    cout << endl;

    root = deleteNode(root, 80);
    cout << "Pre-Order after deleting 80: ";
    preOrder(root);
    cout << endl;

    cout << "Balance Factors:" << endl;
    printBalanceFactors(root);

    cout << "Height of AVL tree: " << root->height << endl;

    return 0;
}
