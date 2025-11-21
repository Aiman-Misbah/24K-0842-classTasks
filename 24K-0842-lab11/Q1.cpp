#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string s)
    {
        data = s;
        next = NULL;
    }
};

class HashTable
{
public:
    int size;
    Node **table;

    HashTable(int s)
    {
        size = s;
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }

    int getHash(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += key[i];
        }
        return sum % size;
    }

    void insertString(string key)
    {
        int index = getHash(key);
        Node *newNode = new Node(key);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            Node *tmp = table[index];
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    void displayTable()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Bucket: " << i << ": ";
            Node *tmp = table[i];
            if (tmp == NULL)
            {
                cout << "Empty";
            }
            while (tmp != NULL)
            {
                cout << tmp->data << "-> ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht(10);
    ht.insertString("Karachi");
    ht.insertString("Lahore");
    ht.insertString("Islamabad");
    ht.insertString("Peshawar");
    ht.insertString("Karachi");
    ht.insertString("Multan");

    ht.displayTable();

    return 0;
}
