#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    int comparisions = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisions++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Elements List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }

    cout << endl
         << "Total Number Of Comparisions Performed: " << comparisions << endl;
}

int main()
{
    int arr[] = {12, 34, 56, 23, 76, 43, 51, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << endl;
    cout << "Original Array Before Sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }

    cout << endl;
    bubbleSort(arr, size);
    cout << endl;
    return 0;
}
