#include <iostream>
using namespace std;

struct AVLNode
{
    int value;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
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

AVLNode *insert(AVLNode *node, int key)
{
    if (!node)
        return new AVLNode(key);

    if (key < node->value)
        node->left = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->value)
        return rightRotate(node);
    if (balance < -1 && key > node->right->value)
        return leftRotate(node);
    if (balance > 1 && key > node->left->value)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(AVLNode *node)
{
    if (node)
    {
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void printBalanceFactors(AVLNode *node)
{
    if (node)
    {
        cout << "Node " << node->value << " Balance Factor: " << getBalance(node) << endl;
        printBalanceFactors(node->left);
        printBalanceFactors(node->right);
    }
}

int main()
{
    AVLNode *root = nullptr;
    int initial[] = {10, 5, 15, 3, 7};
    int n = sizeof(initial) / sizeof(initial[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, initial[i]);

    cout << "Pre-Order before inserting 12: ";
    preOrder(root);
    cout << endl;

    root = insert(root, 12);
    cout << "Pre-Order after inserting 12: ";
    preOrder(root);
    cout << endl;

    cout << "Balance Factors:" << endl;
    printBalanceFactors(root);

    cout << "Height of AVL tree: " << root->height << endl;

    return 0;
}
