#include <bits/stdc++.h>
using namespace std;

vector<int> createLSP(const string &pattern) {
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

void kmp(const string &text, const string &pattern) {
    vector<int> lsp = createLSP(pattern);
    int c = 0;
    bool found = false;
    int i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            if (j != 0) {
                j = lsp[j - 1];
            } else {
                ++i;
            }
        }
        if (j == pattern.size()) {
            c++;
            j = lsp[j - 1];
        }
    }
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    getline(cin, pattern);
    char ch;
    while (cin.get(ch)) {
        if (ch == '\n')
            break;
        text += ch;
    }
    kmp(text, pattern);

    return 0;
}
