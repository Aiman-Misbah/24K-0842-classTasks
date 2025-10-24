#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    string id;
    int salary;
};

void merge(Employee arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee *L = new Employee[n1];
    Employee *R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].salary >= R[j].salary)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    Employee employees[12] = {
        {"Aiman", "E101", 95000},
        {"Bilal", "E102", 70000},
        {"Fatima", "E103", 120000},
        {"Zain", "E104", 85000},
        {"Sara", "E105", 60000},
        {"Ali", "E106", 110000},
        {"Hina", "E107", 50000},
        {"Usman", "E108", 98000},
        {"Maryam", "E109", 73000},
        {"Hamza", "E110", 64000},
        {"Kiran", "E111", 125000},
        {"Danish", "E112", 88000}};

    mergeSort(employees, 0, 11);

    cout << endl
         << "Top 3 Highest Paid Employees:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << employees[i].name << " (" << employees[i].id << ") - PKR " << employees[i].salary << endl;
    }

    return 0;
}
