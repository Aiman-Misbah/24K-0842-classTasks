#include <iostream>
using namespace std;

class Product
{
public:
    string name;
    double price;
    string description;
    string availability;
};

int partition(Product arr[], int low, int high)
{
    double pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].price < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    Product products[3];

    products[0] = {"Mobile Phone", 55000, "Latest 5G model", "In Stock"};
    products[1] = {"Laptop", 125000, "Core i7 12th Gen", "Available"};
    products[2] = {"Smart Watch", 18000, "Waterproof fitness tracker", "Limited Stock"};

    quickSort(products, 0, 2);

    cout << endl
         << "Products sorted by price (ascending):" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Name: " << products[i].name << endl;
        cout << "Price: PKR " << products[i].price << endl;
        cout << "Description: " << products[i].description << endl;
        cout << "Availability: " << products[i].availability << endl
             << endl;
    }

    return 0;
}
