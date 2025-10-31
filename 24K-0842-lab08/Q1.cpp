#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string packageName;
    Node *left;
    Node *right;
    Node(string name)
    {
        packageName = name;
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
        if (node->packageName == name)
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
            cout << "Root package created: " << rootName << endl;
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
            cout << "Parent package not found!" << endl;
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
            cout << "Invalid side! Use L or R only." << endl;
        }
    }

    void display(Node *node, int level = 0)
    {
        if (node == NULL)
            return;
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "- " << node->packageName << endl;
        display(node->left, level + 1);
        display(node->right, level + 1);
    }
};

int main()
{
    BinaryTree tree;
    int n;
    cout << "Enter number of tour packages: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            string rootName;
            cout << "Enter root package name: ";
            getline(cin, rootName);
            tree.insertRoot(rootName);
        }
        else
        {
            string parentName, childName;
            char side;
            cout << "Enter new package name: ";
            getline(cin, childName);
            cout << "Enter parent package name: ";
            getline(cin, parentName);
            cout << "Add to Left or Right of " << parentName << "? (L/R): ";
            cin >> side;
            cin.ignore();
            tree.insertChild(parentName, childName, side);
        }
        cout << endl;
    }

    cout << "Tour Package Hierarchy:" << endl;
    tree.display(tree.root);

    return 0;
}

