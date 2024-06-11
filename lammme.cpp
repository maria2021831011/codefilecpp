#include<bits/stdc++.h>
using namespace std;

// Custom comparator function for sorting the pairs
bool com(const pair<pair<int, int>, int>& a1, const pair<pair<int, int>, int>& b1) {
    if (a1.first.first == b1.first.first) {
        return a1.first.second < b1.first.second;
    }
    return a1.first.first < b1.first.first;
}

int main() {
    string s;
    cin >> s;
    s += "$";  // Append $ to mark the end of the string
    int n = s.size();
    vector<int> p(n), c(n);  // p: positions, c: equivalence classes
    vector<pair<char, int>> a(n);  // Initial pair of character and index

    // Initial sorting based on single characters
    for (int i = 0; i < n; i++) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());

    // Setting up initial positions and equivalence classes
    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n) {  // Build suffix array in log(n) steps
        vector<pair<pair<int, int>, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(b.begin(), b.end(), com);

        // Reassign positions and equivalence classes
        for (int i = 0; i < n; i++) {
            p[i] = b[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (b[i].first == b[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }

    // Output the suffix array
    for (int i = 0; i < n; i++) {
        cout << p[i] << " " << s.substr(p[i], n - p[i]) << endl;
    }

    return 0;
}
