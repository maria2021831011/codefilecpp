
#include<bits/stdc++.h>
using namespace std;

vector<int> createLPS(string pattern) {
    vector<int> lsp(pattern.size());
    int index = 0;
    for (int i = 1; i < pattern.size();) {
        if (pattern[index] == pattern[i]) {
            lsp[i] = index + 1;
            ++index;
            ++i;
        } else {
            if (index != 0) {
                index = lsp[index - 1];
            } else {
                lsp[i] = index;
                ++i;
            }
        }
    }
    return lsp;
}

void kmp(string text, string pattern) {
    vector<int> lps = createLPS(pattern);
    int i = 0, j = 0, c = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
        if (j == pattern.size()) {
            j = lps[j - 1];
            c++;
        }
    }
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    getline(cin, text);
    int t;
    cin >> t;
    cin.ignore(); // to clear the newline character from the buffer
    for (int i = 0; i < t; i++) {
        getline(cin, pattern);
        kmp(text, pattern);
    }
    return 0;
}
