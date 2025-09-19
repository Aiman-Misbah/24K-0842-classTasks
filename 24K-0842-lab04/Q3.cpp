#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }
    cout << endl;
}

void shellSort(int arr[], int size)
{
    int comparisions = 0;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                comparisions++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            if (j >= gap)
            {
                comparisions++;
            }
            arr[j] = temp;
        }
    }

    cout << "Shell Sorted Elements List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }

    cout
        << endl
        << "Total Number Of Comparisions Performed: " << comparisions << endl
        << endl;
}

int main()
{
    int size;
    cout << endl
         << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << endl
         << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << endl
         << "Original Array Elements List: " << endl;
    printArray(arr, size);
    shellSort(arr, size);

    delete[] arr;
    return 0;
}
