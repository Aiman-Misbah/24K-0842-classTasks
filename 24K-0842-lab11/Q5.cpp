#include <iostream>
#include <string>
using namespace std;

class EmployeeHashTable
{
private:
    struct Employee
    {
        string name;
        bool isEmpty;
    };

    Employee table[50];

    int computePrimaryHash(const string &name)
    {
        int sum = 0;
        for (char c : name)
            sum += c;
        return sum % 50;
    }

    int computeSecondaryHash(const string &name)
    {
        int sum = 0;
        for (char c : name)
            sum += c;
        return 7 - (sum % 7);
    }

public:
    EmployeeHashTable()
    {
        for (int i = 0; i < 50; i++)
            table[i].isEmpty = true;
    }

    void Add_Employee(const string &name)
    {
        int h1 = computePrimaryHash(name);
        int h2 = computeSecondaryHash(name);
        int i = 0;

        while (i < 50)
        {
            int index = (h1 + i * h2) % 50;
            if (table[index].isEmpty)
            {
                table[index].name = name;
                table[index].isEmpty = false;
                return;
            }
            i++;
        }
        cout << "Hash table is full. Cannot insert employee." << endl;
    }

    void Search_Employee(const string &name)
    {
        int h1 = computePrimaryHash(name);
        int h2 = computeSecondaryHash(name);
        int i = 0;

        while (i < 50)
        {
            int index = (h1 + i * h2) % 50;
            if (table[index].isEmpty)
            {
                cout << "Employee not found in the directory." << endl;
                return;
            }
            if (table[index].name == name)
            {
                cout << "Employee found: " << name << " at index " << index << endl;
                return;
            }
            i++;
        }
        cout << "Employee not found in the directory." << endl;
    }

    void Display_Table()
    {
        for (int i = 0; i < 50; i++)
        {
            if (!table[i].isEmpty)
            {
                cout << "Index " << i << ": " << table[i].name << endl;
            }
        }
    }
};

int main()
{
    EmployeeHashTable company;

    company.Add_Employee("Ali Khan");
    company.Add_Employee("Sara Ahmed");
    company.Add_Employee("Hassan Raza");
    company.Add_Employee("Fatima Noor");

    cout << "Search for Sara Ahmed:" << endl;
    company.Search_Employee("Sara Ahmed");

    cout << endl
         << "Search for Ahmed Ali:" << endl;
    company.Search_Employee("Ahmed Ali");

    cout << endl
         << "Current Employee Table:" << endl;
    company.Display_Table();

    return 0;
}
