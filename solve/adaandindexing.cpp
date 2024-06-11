
#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct trie {
    struct trie* arr[26];
    ll count;
};

trie* create() {
    struct trie *root =new trie;

    for (int i = 0; i < 26; i++)
        root->arr[i] = NULL;
    root->count = 0;
    return root;
}

void add(trie *root, string s) {
    ll len = s.length();
    if (len == 0)
        return;
    for (ll index = 0; index < len; index++) {int i=s[index]-'a';
        if (!root->arr[i])
            root->arr[i] = create();
        root = root->arr[i];
        root->count++;
    }
}

ll find(trie *root, string s) {
    ll len = s.length();
    if (len == 0)
        return 0;
    for (ll index = 0; index < len; index++) {int i=s[index]-'a';
        if (!root->arr[i])
            return 0;
        root = root->arr[i];
    }
    return root->count;
}

int main() {
    ll n, q;
    cin >> n >> q;
    trie *root = create();
    while (n--) {
        string s;
        cin >> s;
        ll len = s.length();
        if (len >= 1)
            add(root, s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << find(root, s) << endl;
    }
    return 0;
}
