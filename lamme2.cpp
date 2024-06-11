
#include<bits/stdc++.h>
using namespace std;

// Function to create the LPS (Longest Prefix Suffix) array
vector<int> createLPS(string p) {
    vector<int> lps(p.size());
    lps[0] = 0;
    int index = 0;
    int i = 1; // Starting from the second character
    while (i < p.size()) {
        if (p[i] == p[index]) {
            lps[i] = index + 1;
            ++i;
            ++index;
        } else {
            if (index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

// KMP algorithm to find pattern p in text t
void kmp(string t, string p) {
    vector<int> lps = createLPS(p);
    int ti = 0, pi = 0;
    bool found = false;

    while (ti < t.size()) {
        if (t[ti] == p[pi]) {
            ++ti;
            ++pi;
        }

        if (pi == p.size()) {
            cout << "Pattern found at index " << ti - pi+1 << endl;
            found = true;
            pi = lps[pi - 1]; // Reset pi using LPS array
        } else if (ti < t.size() && t[ti] != p[pi]) {
            if (pi != 0) {
                pi = lps[pi - 1];
            } else {
                ++ti;
            }
        }
    }

    if (!found) {
        cout << "Pattern not found" << endl;
    }
}

int main() {
    string t, p;
    getline(cin, t);
    getline(cin, p);
    kmp(t, p);
    return 0;
}
