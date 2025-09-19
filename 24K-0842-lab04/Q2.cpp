#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << (i + 1) << endl;
    }
}

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

    cout << "Bubble Sorted Elements List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }

    cout
        << endl
        << "Total Number Of Comparisions Performed: " << comparisions << endl
        << endl;
}

void insertionSort(int arr[], int size)
{
    int comparisions = 0;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparisions++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0)
        {
            comparisions++;
        }
        arr[j + 1] = key;
    }

    cout << "Insertion Sorted Elements List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }

    cout
        << endl
        << "Total Number Of Comparisions Performed: " << comparisions << endl
        << endl;
}

void selectionSort(int arr[], int size)
{
    int comparisions = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisions++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Selection Sorted Elements List: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": " << arr[i] << endl;
    }

    cout
        << endl
        << "Total Number Of Comparisions Performed: " << comparisions << endl
        << endl;
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
    srand(time(0));
    const int size20 = 20;
    int arr20[size20];

    cout << "Original Array Elements List: " << endl;
    for (int i = 0; i < size20; i++)
    {
        arr20[i] = rand() % 100 + 1;
        cout << "Element " << (i + 1) << ": " << arr20[i] << endl;
    }
    cout << endl
         << endl;

    int bubbleArr[20], insertionArr[20], selectionArr[20], shellArr[20];

    for (int i = 0; i < size20; i++)
    {
        bubbleArr[i] = arr20[i];
        insertionArr[i] = arr20[i];
        selectionArr[i] = arr20[i];
        shellArr[i] = arr20[i];
    }

    bubbleSort(bubbleArr, size20);
    insertionSort(insertionArr, size20);
    selectionSort(selectionArr, size20);
    shellSort(shellArr, size20);

    cout << "Array with 100 random integers: " << endl;
    const int size100 = 100;
    int arr100[size100];
    for (int i = 0; i < size20; i++)
    {
        arr100[i] = arr20[i];
    }

    for (int i = size20; i < size100; i++)
    {
        arr100[i] = rand() % 100 + 1;
        cout << "Element " << (i + 1) << ": " << arr100[i] << endl;
    }

    return 0;
}
