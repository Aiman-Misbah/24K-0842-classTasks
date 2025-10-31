#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;
    Node *foundSubtree;

    BinaryTree()
    {
        root = NULL;
        foundSubtree = NULL;
    }

    Node *insertLevelOrder(int arr[], int i, int n)
    {
        if (i < n)
        {
            Node *temp = new Node(arr[i]);
            temp->left = insertLevelOrder(arr, 2 * i + 1, n);
            temp->right = insertLevelOrder(arr, 2 * i + 2, n);
            return temp;
        }
        return NULL;
    }

    int findSubtreeSum(Node *node, int target)
    {
        if (node == NULL)
            return 0;

        int leftSum = findSubtreeSum(node->left, target);
        int rightSum = findSubtreeSum(node->right, target);
        int total = node->data + leftSum + rightSum;

        if (total == target && foundSubtree == NULL)
            foundSubtree = node;

        return total;
    }

    void display(Node *node, int level = 0)
    {
        if (node == NULL)
            return;
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "- " << node->data << endl;
        display(node->left, level + 1);
        display(node->right, level + 1);
    }
};

int main()
{
    BinaryTree tree;
    int n;
    cout << "Enter number of warehouse sections: ";
    cin >> n;

    int arr[100];
    cout << "Enter number of items in each section (level order):" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    tree.root = tree.insertLevelOrder(arr, 0, n);

    int target;
    cout << "Enter target sum of items to find: ";
    cin >> target;

    tree.findSubtreeSum(tree.root, target);

    cout << endl;
    if (tree.foundSubtree != NULL)
    {
        cout << "Subtree found with target sum " << target << ":" << endl;
        tree.display(tree.foundSubtree);
    }
    else
    {
        cout << "No subtree found with sum equal to " << target << endl;
    }

    return 0;
}
