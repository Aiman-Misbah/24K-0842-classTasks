#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string levelName;
    Node *left;
    Node *right;
    Node(string name)
    {
        levelName = name;
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
        if (node->levelName == name)
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
            cout << "Root level created: " << rootName << endl;
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
            cout << "Parent level not found!" << endl;
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
            cout << "Invalid side! Use L or R." << endl;
        }
    }

    bool isFullBinaryTree(Node *node)
    {
        if (node == NULL)
            return true;
        if ((node->left == NULL && node->right != NULL) ||
            (node->left != NULL && node->right == NULL))
            return false;
        return isFullBinaryTree(node->left) && isFullBinaryTree(node->right);
    }

    void display(Node *node, int level = 0)
    {
        if (node == NULL)
            return;
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "- " << node->levelName << endl;
        display(node->left, level + 1);
        display(node->right, level + 1);
    }
};

int main()
{
    BinaryTree tree;

    cout << "Building Game Level Hierarchy..." << endl
         << endl;
         
    tree.insertRoot("Adventure in Pakistan");

    tree.insertChild("Adventure in Pakistan", "Karachi Mission", 'L');
    tree.insertChild("Adventure in Pakistan", "Lahore Quest", 'R');

    tree.insertChild("Karachi Mission", "Clifton Beach Chase", 'L');
    tree.insertChild("Karachi Mission", "Port Grand Escape", 'R');

    tree.insertChild("Lahore Quest", "Badshahi Fort Battle", 'L');
    tree.insertChild("Lahore Quest", "Mall Road Race", 'R');

    tree.insertChild("Clifton Beach Chase", "Sand Dune Sprint", 'L');
    tree.insertChild("Clifton Beach Chase", "Sea View Rescue", 'R');

    cout << endl
         << "Game Level Hierarchy:" << endl;
    tree.display(tree.root);
    cout << endl;

    if (tree.isFullBinaryTree(tree.root))
        cout << "Result: The tree is a Full Binary Tree." << endl;
    else
        cout << "Result: The tree is NOT a Full Binary Tree." << endl;

    return 0;
}
