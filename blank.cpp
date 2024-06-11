
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> suffixArray(const string& s) {
    int n = s.length();
    vector<int> sa(n), rank(n);
    vector<pair<int, int>> temp(n);

    // Initialize ranks
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = s[i];
    }

    // Sort suffixes by first character
    for (int len = 1; len < n; len *= 2) {
        for (int i = 0; i < n; ++i) {
            temp[i] = {rank[i], (i + len < n) ? rank[i + len] : -1};
        }
        sort(temp.begin(), temp.end());
        for (int i = 0, r = 0; i < n; ++i) {
            if (i > 0 && temp[i] != temp[i - 1]) {
                r++;
            }
            sa[i] = temp[i].first;
            rank[i] = r;
        }
    }

    return sa;
}

int countDistinctSubstrings(const string& s) {
    int n = s.length();
    vector<int> sa = suffixArray(s);
    int distinctSubstrings = 0;
    set<string> seen;

    // Count distinct substrings
    for (int i = 0; i < n; ++i) {
        int len = n - sa[i];
        for (int j = 0; j < len; ++j) {
            string substring = s.substr(sa[i], j + 1);
            if (!seen.count(substring)) {
                seen.insert(substring);
                distinctSubstrings++;
            }
        }
    }

    return distinctSubstrings;
}

int main() {
    string s;
    cin >> s;

    cout << countDistinctSubstrings(s) << endl;

    return 0;
}
