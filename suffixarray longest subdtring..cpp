
#include<bits/stdc++.h>
using namespace std;

// Function to build the suffix array
vector<int> buildSuffixArray(string s) {
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n); // p - ordering of the strings, c - equivalence classes

    {
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
    }

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
vector<int> buildLCPArray(string s, vector<int> &p) {
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

// Function to find the longest repeated substring
string longestRepeatedSubstring(string s) {
    vector<int> suffixArray = buildSuffixArray(s);
    vector<int> lcp = buildLCPArray(s, suffixArray);

    int maxLCP = 0, index = 0;
    for (int i = 1; i < lcp.size(); i++) {
        if (lcp[i] > maxLCP) {
            maxLCP = lcp[i];
            index = suffixArray[i];
        }
    }
    return s.substr(index, maxLCP);
}

int main() {
    string s = "ababba";
    string lrs = longestRepeatedSubstring(s);
    cout << "Longest Repeated Substring: " << lrs << endl;
    return 0;
}
