#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h) {
    int i = l;
    int j = h;
    int pivot = a[l];

    while (i < j) {
        while (a[i] <= pivot && i < h) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);
    return j;
}

void quicksort(int a[], int l, int h) {
    if (l < h) {
        int j = partition(a, l, h);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, h);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int h = n - 1;

    quicksort(a, l, h);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
