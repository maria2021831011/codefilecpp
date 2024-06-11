

#include <bits/stdc++.h>
using namespace std;

const int alpha= 26;

struct TrieNode {
    bool isend;
    int child[alpha], c;
    TrieNode() {
        isend= false;
        c=0;
        memset(child, 0, sizeof(child));
    }
};

TrieNode Node[1048576];
int TrieSize;

void insertTrie(const string& str) {
    int idx = 0;
    for (char it : str) {
        if (!Node[idx].child[it - 'a']) {
            Node[idx].child[it- 'a'] = ++TrieSize;
            Node[TrieSize] = TrieNode();
        }
        idx = Node[idx].child[it- 'a'];
        Node[idx].c++;
    }
    Node[idx].isend= true;
}

long long ans;

void dfs(int nd, int dep) {
    for (int i = 0; i < alpha; i++) {
        if (Node[nd].child[i]) {
            dfs(Node[nd].child[i], dep + 1);
            if (Node[nd].c != 1 && Node[Node[nd].child[i]].c== 1)
                ans += dep;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        TrieSize = 0;
        Node[0] = TrieNode();
        while (n--) {
            string str;
            cin >> str;
            insertTrie(str);
        }
        ans = 0;
        dfs(0, 1);
        cout << ans << endl;
    }
    return 0;
}
