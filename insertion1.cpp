#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t, j;

    // Input the size of the array
    cin >> n;

    int a[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = t;
    }

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
