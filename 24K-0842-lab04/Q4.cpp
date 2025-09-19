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
    cout << "Shell Sorted Elements List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }
}

int interpolationSearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[high] == arr[low])
        {
            if (arr[low] == key)
            {
                return low;
            }
            else
            {
                return -1;
            }
        }

        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key)
        {
            return pos;
        }
        else if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter " << size << " elements separated by spaces: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << endl
         << "Original Array Elements List: " << endl;
    printArray(arr, size);
    cout<<endl;
    shellSort(arr, size);
    cout << endl
         << "Original Array Elements List: " << endl;
    printArray(arr, size);

    int key;
    cin >> key;

    int index = interpolationSearch(arr, size, key);

    if (index != -1)
    {
        cout << "Element " << key << " found at position " << (index + 1) << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the array." << endl;
    }

    delete[] arr;
    return 0;
}
