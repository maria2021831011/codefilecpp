
#include <bits/stdc++.h>
using namespace std;
struct node {
    int goCount = 0;
    node *next[2] = {NULL};
} *root;

int mx;

void insert(char str[]) {
    int len = strlen(str);
    node *curr = root;
    for (int i = 0; i < len; ++i) {
        ++(curr->goCount);
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    ++(curr->goCount);
}

void prefixGoodness(node *curr, int len) {
    for (int i = 0; i < 2; ++i)
        if (curr->next[i])
            prefixGoodness(curr->next[i], len + 1);

    mx = max(mx, curr->goCount * len);
}
void del(node *curr) {
    for (int i = 0; i < 2; ++i)
        if (curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        char str[205];
        root = new node();
        while (n--) {
            cin >> str;
            insert(str);
        }
        mx = 0;
        prefixGoodness(root, 0);
        cout << mx << endl;
        del(root);
    }

    return 0;
}
