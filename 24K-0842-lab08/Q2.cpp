#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string clientName;
    Node *left;
    Node *right;
    Node(string name)
    {
        clientName = name;
        left = right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    Node *findNode(Node *node, const string &name)
    {
        if (node == NULL)
            return NULL;
        if (node->clientName == name)
            return node;
        Node *leftResult = findNode(node->left, name);
        if (leftResult)
            return leftResult;
        return findNode(node->right, name);
    }

    void insertRoot(const string &rootName)
    {
        if (root == NULL)
        {
            root = new Node(rootName);
            cout << "Root client created: " << rootName << endl;
        }
        else
        {
            cout << "Root already exists!" << endl;
        }
    }

    void insertChild(const string &parentName, const string &childName, char side)
    {
        Node *parent = findNode(root, parentName);
        if (parent == NULL)
        {
            cout << "Parent client not found!" << endl;
            return;
        }

        if (side == 'L' || side == 'l')
        {
            if (parent->left == NULL)
            {
                parent->left = new Node(childName);
                cout << "Added " << childName << " to LEFT of " << parentName << endl;
            }
            else
            {
                cout << "Left child already exists for " << parentName << "!" << endl;
            }
        }
        else if (side == 'R' || side == 'r')
        {
            if (parent->right == NULL)
            {
                parent->right = new Node(childName);
                cout << "Added " << childName << " to RIGHT of " << parentName << endl;
            }
            else
            {
                cout << "Right child already exists for " << parentName << "!" << endl;
            }
        }
        else
        {
            cout << "Invalid side choice! Use L or R." << endl;
        }
    }

    int countNodes(Node *node)
    {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(Node *node)
    {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int findHeight(Node *node)
    {
        if (node == NULL)
            return 0;
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    void display(Node *node, int level = 0)
    {
        if (node == NULL)
            return;
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "- " << node->clientName << endl;
        display(node->left, level + 1);
        display(node->right, level + 1);
    }
};

int main()
{
    BinaryTree tree;

    cout << "Building Client Data Tree..." << endl
         << endl;

    tree.insertRoot("TechCorp Pakistan");

    tree.insertChild("TechCorp Pakistan", "Lahore Branch", 'L');
    tree.insertChild("TechCorp Pakistan", "Karachi Branch", 'R');

    tree.insertChild("Lahore Branch", "Client Ali (PKR 50000)", 'L');
    tree.insertChild("Lahore Branch", "Client Sara (PKR 75000)", 'R');

    tree.insertChild("Karachi Branch", "Client Hamza (PKR 65000)", 'L');
    tree.insertChild("Karachi Branch", "Client Fatima (PKR 90000)", 'R');

    tree.insertChild("Client Ali (PKR 50000)", "Subclient Hina (+92 3341234567)", 'L');
    tree.insertChild("Client Ali (PKR 50000)", "Subclient Zain (+92 3129876543)", 'R');

    cout << endl
         << "Client Data Tree Structure:" << endl;
    tree.display(tree.root);
    cout << endl;

    int totalNodes = tree.countNodes(tree.root);
    int leafNodes = tree.countLeaves(tree.root);
    int height = tree.findHeight(tree.root);

    cout << "Total Clients (including branches): " << totalNodes << endl;
    cout << "Leaf Clients (no sub-clients): " << leafNodes << endl;
    cout << "Height of Client Tree: " << height << endl;

    return 0;
}
