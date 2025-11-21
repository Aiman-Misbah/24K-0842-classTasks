#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string word;
    Node *next;
    Node(string w)
    {
        word = w;
        next = NULL;
    }
};

class Dictionary
{
public:
    Node **table;
    int size;

    Dictionary()
    {
        size = 100;
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

    void Add_Record(string key)
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

    void Word_Search(string key)
    {
        int index = getHash(key);
        Node *tmp = table[index];
        while (tmp != NULL)
        {
            if (tmp->word == key)
            {
                cout << "Word Found: " << key << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "Error: Word not found in dictionary" << endl;
    }

    void Print_Dictionary()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *tmp = table[i];
            if (tmp == NULL)
            {
                cout << "Empty";
            }
            while (tmp != NULL)
            {
                cout << tmp->word << "-> ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Dictionary dict;
    
    dict.Add_Record("Karachi");
    dict.Add_Record("Lahore");
    dict.Add_Record("Islamabad");
    dict.Add_Record("Multan");
    dict.Add_Record("Faisalabad");
    dict.Add_Record("Karachi");

    dict.Word_Search("Multan");
    dict.Word_Search("Rawalpindi");

    dict.Print_Dictionary();

    return 0;
}
