#include <iostream>
using namespace std;

struct Node
{
    int productID;
    int quantity;
    Node *left;
    Node *right;
    Node(int id, int qty)
    {
        productID = id;
        quantity = qty;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *insert(Node *node, int id, int qty)
    {
        if (node == NULL)
            return new Node(id, qty);

        if (id < node->productID)
            node->left = insert(node->left, id, qty);
        else if (id > node->productID)
            node->right = insert(node->right, id, qty);
        else
            node->quantity = qty;

        return node;
    }

    Node *search(Node *node, int id)
    {
        if (node == NULL || node->productID == id)
            return node;
        if (id < node->productID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << "Product ID: " << node->productID << " | Quantity: " << node->quantity << endl;
        inorder(node->right);
    }

    Node *findMaxQuantity(Node *node, Node *&maxNode)
    {
        if (node == NULL)
            return maxNode;
        if (maxNode == NULL || node->quantity > maxNode->quantity)
            maxNode = node;
        findMaxQuantity(node->left, maxNode);
        findMaxQuantity(node->right, maxNode);
        return maxNode;
    }
};

int main()
{
    BST store;

    store.root = store.insert(store.root, 105, 20);
    store.root = store.insert(store.root, 101, 15);
    store.root = store.insert(store.root, 120, 30);
    store.root = store.insert(store.root, 110, 25);
    store.root = store.insert(store.root, 130, 10);

    cout << "Complete Product List (Sorted by Product ID):" << endl;
    store.inorder(store.root);
    cout << endl;

    int searchID = 110;
    Node *found = store.search(store.root, searchID);
    if (found != NULL)
        cout << "Product ID " << searchID << " found with Quantity: " << found->quantity << endl;
    else
        cout << "Product ID " << searchID << " not found in inventory." << endl;
    cout << endl;

    Node *maxNode = NULL;
    store.findMaxQuantity(store.root, maxNode);
    cout << "Product with highest stock:" << endl;
    cout << "Product ID: " << maxNode->productID << " | Quantity: " << maxNode->quantity << endl;

    return 0;
}
