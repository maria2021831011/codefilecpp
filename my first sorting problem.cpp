#include<bits/stdc++.h>
using namespace std;

// Function to check if the matrix can be square
bool isSquareBeautifulMatrix(int n, string &s) {
    // Find the square root of n
    int sqrt_n = sqrt(n);

    // If n is not a perfect square, return false
    if (sqrt_n * sqrt_n != n) return false;

    int r = sqrt_n;
    int c = sqrt_n;

    // Check the edges of the matrix, corners, and internal elements
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int idx = i * c + j;
            // Check if internal elements are '0' and edges are '1'
            if ((i == 0 || i == r - 1 || j == 0 || j == c - 1)) {
                if (s[idx] != '1') return false;
            } else {
                if (s[idx] != '0') return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (isSquareBeautifulMatrix(n, s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
