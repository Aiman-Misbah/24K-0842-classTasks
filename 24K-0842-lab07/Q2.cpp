#include <iostream>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner *L = new Runner[n1];
    Runner *R = new Runner[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Runner runners[10] = {
        {"Ali", 3600},
        {"Sara", 3420},
        {"Usman", 3550},
        {"Hina", 3390},
        {"Bilal", 3700},
        {"Zain", 3300},
        {"Ayesha", 3250},
        {"Ahmed", 3450},
        {"Fatima", 3400},
        {"Hamza", 3650}
    };

    int n = 10;
    mergeSort(runners, 0, n - 1);

    cout << "Top 5 Fastest Runners:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].time << " seconds" << endl;
    }

    return 0;
}
