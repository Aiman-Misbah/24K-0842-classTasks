#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }
}

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << endl
         << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << endl
         << "Original Array: " << endl;
    printArray(arr, size);

    shellSort(arr, size);
    cout << endl
         << "Sorted Array: " << endl;
    printArray(arr, size);

    int key;
    cout << endl
         << "Enter the element to search for: ";
    cin >> key;

    int index = binarySearch(arr, size, key);

    if (index != -1)
    {
        cout << "Element " << key << " found at position " << (index + 1) << endl
             << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the array." << endl
             << endl;
    }

    delete[] arr;
    return 0;
}
