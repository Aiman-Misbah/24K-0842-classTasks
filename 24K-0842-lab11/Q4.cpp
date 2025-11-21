#include <iostream>
#include <string>
using namespace std;

class StudentHashTable
{
private:
    struct Student
    {
        int roll;
        string name;
        bool isEmpty;
    };

    Student table[15];

    int Hash(int rollN)
    {
        return rollN % 15;
    }

public:
    StudentHashTable()
    {
        for (int i = 0; i < 15; i++)
        {
            table[i].isEmpty = true;
        }
    }

    void insertRecord(int rollN, string n)
    {
        int index = Hash(rollN);
        int attempt = 0;

        while (!table[(index + attempt * attempt) % 15].isEmpty && attempt < 15)
        {
            attempt++;
        }

        if (attempt == 15)
        {
            cout << "Hash table is full.Cannot insert record." << endl;
            return;
        }

        int finalI = (index + attempt * attempt) % 15;
        table[finalI].roll = rollN;
        table[finalI].name = n;
        table[finalI].isEmpty = false;
    }

    void searchRecord(int rollN)
    {
        int index = Hash(rollN);
        int attempt = 0;

        while (attempt < 15)
        {
            int curr = (index + attempt * attempt) % 15;
            if (table[curr].isEmpty)
            {
                cout << "Record not found." << endl;
                return;
            }
            if (table[curr].roll == rollN)
            {
                cout << "Student Name: " << table[curr].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found." << endl;
    }

    void displayTable()
    {
        for (int i = 0; i < 15; i++)
        {
            if (!table[i].isEmpty)
            {
                cout << "Index " << i << ": " << table[i].roll << " - " << table[i].name << endl;
            }
        }
    }
};

int main()
{
    StudentHashTable s;

    s.insertRecord(101, "Ali Khan");
    s.insertRecord(116, "Sara Ahmed");
    s.insertRecord(131, "Hassan Raza");
    s.insertRecord(102, "Fatima Noor");

    cout << "Search for Roll Number 116: " << endl;
    s.searchRecord(116);

    cout << "Search for Roll Number 150: " << endl;
    s.searchRecord(150);

    cout << "Current Student Table: " << endl;
    s.displayTable();
    return 0;
}
