#include <iostream>
using namespace std;

int getMax(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

void countSort(int a[], int n, int exp)
{
    int out[100];
    int cnt[10] = {0};

    for (int i = 0; i < n; i++)
        cnt[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        out[cnt[(a[i] / exp) % 10] - 1] = a[i];
        cnt[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = out[i];
}

void radixSort(int a[], int n)
{
    int m = getMax(a, n);
    for (int e = 1; m / e > 0; e *= 10)
        countSort(a, n, e);
}

int main()
{
    int a[50] = {88, 74, 96, 59, 33, 82, 45, 100, 67, 71,
                 90, 63, 78, 52, 69, 85, 43, 92, 80, 58,
                 49, 65, 99, 40, 73, 61, 84, 46, 70, 55,
                 95, 38, 64, 79, 81, 91, 36, 87, 57, 60,
                 66, 76, 97, 35, 50, 41, 56, 94, 83, 68};
    int n = 50;

    radixSort(a, n);

    cout << "Rank\tScore" << endl;
    for (int i = 0; i < n; i++)  
        cout << i + 1 << "\t" << a[i] << endl;

    return 0;
}
