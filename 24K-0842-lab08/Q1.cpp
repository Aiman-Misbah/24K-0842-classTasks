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

    cout << "Building Tour Package Hierarchy..." << endl
         << endl;

    tree.insertRoot("Pakistan Tours");

    tree.insertChild("Pakistan Tours", "Northern Areas", 'L');
    tree.insertChild("Pakistan Tours", "Southern Adventures", 'R');

    tree.insertChild("Northern Areas", "Hunza Valley Package", 'L');
    tree.insertChild("Northern Areas", "Skardu Expedition", 'R');

    tree.insertChild("Southern Adventures", "Karachi Beach Tour", 'L');
    tree.insertChild("Southern Adventures", "Gwadar Coastal Drive", 'R');

    tree.insertChild("Hunza Valley Package", "Karimabad Special", 'L');
    tree.insertChild("Hunza Valley Package", "Khunjerab Pass Visit", 'R');

    cout << endl
         << "Final Tour Package Hierarchy:" << endl;
    tree.display(tree.root);
    cout << endl;

    return 0;
}
