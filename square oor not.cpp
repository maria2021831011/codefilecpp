
#include<bits/stdc++.h>
using namespace std;
bool isSquareBeautifulMatrix(int n, string &s) {
    int sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n != n) return false;

    int r = sqrt_n;
    int c = sqrt_n;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int idx = i * c + j;
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
