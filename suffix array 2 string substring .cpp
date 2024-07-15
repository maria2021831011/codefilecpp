
#include<bits/stdc++.h>
using namespace std;

// Function to build the suffix array
vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> p(n), c(n);

    // k = 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
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

    // Iteratively build the suffix array for k = 1, 2, 4, 8, ...
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());
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
        k++;
    }
    return p;
}

// Function to build the LCP array
vector<int> buildLCPArray(const string &s, const vector<int> &p) {
    int n = s.size();
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) rank[p[i]] = i;
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = p[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}

// Function to find the length of the longest common substring between two strings
int longestCommonSubstringLength(const string &s1, const string &s2) {
    string combined = s1 + "#" + s2 + "$";
    vector<int> suffixArray = buildSuffixArray(combined);
    vector<int> lcp = buildLCPArray(combined, suffixArray);

    int maxLCP = 0;
    for (int i = 1; i < lcp.size(); i++) {
        // Check if the suffixes are from different original strings
        if ((suffixArray[i] < s1.size() && suffixArray[i - 1] > s1.size()) ||
            (suffixArray[i] > s1.size() && suffixArray[i - 1] < s1.size())) {
            maxLCP = max(maxLCP, lcp[i]);
        }
    }
    return maxLCP;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int lcsLength = longestCommonSubstringLength(s1, s2);
        cout << lcsLength << endl;
    }
    return 0;
}
