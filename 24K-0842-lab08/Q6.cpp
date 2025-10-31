#include <iostream>
using namespace std;

struct Node
{
    int empID;
    Node *left;
    Node *right;
    Node(int id)
    {
        empID = id;
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

    Node *insert(Node *node, int id)
    {
        if (node == NULL)
            return new Node(id);
        if (id < node->empID)
            node->left = insert(node->left, id);
        else if (id > node->empID)
            node->right = insert(node->right, id);
        return node;
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->empID << " ";
        inorder(node->right);
    }

    Node *findLCA(Node *node, int id1, int id2)
    {
        if (node == NULL)
            return NULL;
        if (id1 < node->empID && id2 < node->empID)
            return findLCA(node->left, id1, id2);
        if (id1 > node->empID && id2 > node->empID)
            return findLCA(node->right, id1, id2);
        return node;
    }
};

int main()
{
    BST company;
    company.root = company.insert(company.root, 50);
    company.root = company.insert(company.root, 30);
    company.root = company.insert(company.root, 70);
    company.root = company.insert(company.root, 20);
    company.root = company.insert(company.root, 40);
    company.root = company.insert(company.root, 60);
    company.root = company.insert(company.root, 80);

    cout << "Employee Hierarchy (Inorder Traversal of IDs): " << endl;
    company.inorder(company.root);
    cout << endl
         << endl;

    int emp1 = 20;
    int emp2 = 40;

    cout << "Finding common manager for Employee IDs " << emp1 << " and " << emp2 << "..." << endl;
    Node *manager = company.findLCA(company.root, emp1, emp2);
    cout << "Closest Common Manager (Lowest Common Ancestor): Employee ID " << manager->empID << endl;

    return 0;
}
