#include<bits/stdc++.h>
using namespace std;
vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> p(n), c(n);

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

int longestRepeatedSubstringLength(const string &s) {
    vector<int> suffixArray = buildSuffixArray(s);
    vector<int> lcp = buildLCPArray(s, suffixArray);

    int maxLCP = 0;
    for (int i = 1; i < lcp.size(); i++) {
        maxLCP = max(maxLCP, lcp[i]);
    }
    return maxLCP;
}

int main() {int t;
cin>>t;
while(t--){
    string s ;
    cin>>s;
     int lrsLength = longestRepeatedSubstringLength(s);
    cout  << lrsLength << endl;}
    return 0;
}
