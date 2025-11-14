#include <iostream>
using namespace std;

struct Node
{
    int roll;
    Node *left;
    Node *right;
    int height;

    Node(int val): roll(val), left(nullptr), right(nullptr), height(1){}
};

int getHeight(Node *node)
{
    if (node != nullptr)
    {
        return node->height;
    }
    return 0;
}

int getBalance(Node *node)
{
    if (node != nullptr)
    {
        return getHeight(node->left) - getHeight(node->right);
    }
    return 0;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    Node *T2 = y->right;
    y->right = x;
    x->left = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node *insert(Node *node, int key)
{
    if (!node)
    {
        return new Node(key);
    }

    if (key < node->roll)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->roll)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->roll)
        return rightRotate(node);
    if (balance < -1 && key > node->right->roll)
        return leftRotate(node);
    if (balance > 1 && key > node->left->roll) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->roll) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *node)
{
    if (node)
    {
        cout << node->roll << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main()
{
    Node *root = nullptr;
    int initial[] = {10, 20, 30, 40, 50};
    int s = sizeof(initial) / sizeof(initial[0]);
    for (int i = 0; i < s; i++)
    {
        root = insert(root, initial[i]);
    }

    cout << "Pre-Order Traversal Before Inserting: ";
    preOrder(root);
    cout << endl;

    root = insert(root, 12);
    cout << "Pre-Order Traversal After Inserting: ";
    preOrder(root);
    cout << endl;

    cout << "Height: " << root->height << endl;
    return 0;
}
