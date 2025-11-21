#include <iostream>
using namespace std;

class Hash
{
public:
    int size;
    int *table;

    Hash(int s)
    {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }

    int getHash(int key)
    {
        return key % size;
    }

    void insertKey(int key)
    {
        int index = getHash(key);
        int start = index;
        while (table[index] != -1 && table[index] != -2)
        {
            index = (index + 1) % size;
            if (index == start)
            {
                return;
            }
        }
        table[index] = key;
    }

    void deleteKey(int key)
    {
        int index = getHash(key);
        int start = index;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                table[index] = -2;
                return;
            }
            index = (index + 1) % size;
            if (index == start)
            {
                return;
            }
        }
        cout << "Key not found for deletion: " << key << endl;
    }

    void searchKey(int key)
    {
        int index = getHash(key);
        int start = index;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                cout << "Key found at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start)
                break;
        }
        cout << "Key not found: " << key << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main()
{
    Hash h(10);

    h.insertKey(42301);
    h.insertKey(75219);
    h.insertKey(99123);
    h.insertKey(12345);
    h.insertKey(75219);

    h.searchKey(99123);
    h.searchKey(55555);

    h.deleteKey(75219);
    h.deleteKey(88888);

    h.display();

    return 0;
}
