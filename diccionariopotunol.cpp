
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    int link[26];
};

Trie Node[1 << 21];
int TrieSize = 0;

int suffix[26] = {}, ending[26] = {};

void insertTrie(int root, const string& str) {
    int idx = root;
    for (char c : str) {
        if (Node[idx].link[c - 'a'] == 0) {
            TrieSize++;
            memset(&Node[TrieSize], 0, sizeof(Node[0]));
            Node[idx].link[c - 'a'] = TrieSize;
        }
        idx = Node[idx].link[c - 'a'];
    }
}

void insertTrieSuffix(int root, const string& str) {
    int idx = root;
    int L = str.length();
    ending[str[L - 1] - 'a']++;
    for (int i = L - 1; i >= 0; i--) {
        if (Node[idx].link[str[i] - 'a'] == 0) {
            TrieSize++;
            memset(&Node[TrieSize], 0, sizeof(Node[0]));
            Node[idx].link[str[i] - 'a'] = TrieSize;
            suffix[str[i] - 'a']++;
        }
        idx = Node[idx].link[str[i] - 'a'];
    }
}

long long ret = 0;

void dfs(int idx, int root) {
    for (int i = 0; i < 26; i++) {
        if (Node[idx].link[i]) {
            dfs(Node[idx].link[i], root);
            if (idx != root && ending[i])
                ret++; // greedy
        } else {
            if (idx != root)
                ret += suffix[i];
        }
    }
}

int main() {
    int n, m;
    string s;
    while (cin >> n >> m && (n || m)) {
        memset(suffix, 0, sizeof(suffix));
        memset(ending, 0, sizeof(ending));

        int root1 = 0, root2 = 1;
        TrieSize = 1;
        memset(&Node[root1], 0, sizeof(Node[root1]));
        memset(&Node[root2], 0, sizeof(Node[root2]));

        for (int i = 0; i < n; i++) {
            cin >> s;
            insertTrie(root1, s);
        }
        for (int i = 0; i < m; i++) {
            cin >> s;
            insertTrieSuffix(root2, s);
        }

        ret = 0;
        dfs(root1, root1);
        cout << ret << endl;
    }
    return 0;
}
