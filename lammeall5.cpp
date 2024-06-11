#include <bits/stdc++.h>
using namespace std;
/*
struct Trie {
    Trie* children[26];
    int index;  // To store the index of the word if it ends here

    Trie() {
        index = -1;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void build(Trie* root, const string& s, int idx) {
    Trie* node = root;
    for (char ch : s) {
        int c = ch - 'a';
        if (node->children[c] == NULL) {
            node->children[c] = new Trie();
        }
        node = node->children[c];
    }
    node->index = idx;  // Set the index at the end of the word
}

int search(Trie* root, const string& s) {
    Trie* node = root;
    for (char ch : s) {
        int c = ch - 'a';
        if (node->children[c] == NULL) {
            return -1;
        }
        node = node->children[c];
    }
    return node->index;  // Return the index if the word is found
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n + 1);  // One-based indexing
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }

    string par;
    cin >> par;

    Trie* root = new Trie();
    for (int i = 1; i <= n; i++) {
        build(root, words[i], i);
    }

    int foundIndex = search(root, par);
    if (foundIndex != -1) {
        cout << "Found at index: " << foundIndex << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}*/
/*const int N=100005;
int a[N];
int tree[4*N];
void build(int node,int start,int en)
{
    if(start==en)
    {
        tree[node]=a[start];
    }else
    {
        int mid=(start+en)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,en);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
void update(int node,int start,int en,int index,int val)
{
    if(start==en)
    { a[index]+=val;
        tree[node]+=val;;
    }else
    {
        int mid=(start+en)/2;
        if(start<=index&&index<=mid){
        update(2*node,start,mid,index,val);}
        else
        {
        update(2*node+1,mid+1,en,index,val);
        }
        tree[node]=tree[node*2]+tree[node*2+1];
    }

}
int querry(int node,int start,int en,int l,int r)
{
    if(r<start||en<l)
    {
        return 0;
    }if(l<=start&&en<=r)
    {
        return tree[node];
    }
     int mid=(start+en)/2;

       int p= querry(2*node,start,mid,l,r);


    int q=querry(2*node+1,mid+1,en,l,r);

    return (p+q);
    }


int main()
{
    int n,l,r,val,index;
    cin>>n>>l>>r>>val>>index;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
     build(1,1,n);
     cout<<querry(1,1,n,l,r)<<endl;
     update(1,1,n,index,val);
     cout<<querry(1,1,n,l,r);

}*/
#include <iostream>
#include <vector>

using namespace std;

const int mx = 100005;
vector<int> v(mx, 0);

int bit(int x) {
    int sum = 0;
    while (x > 0) {
        sum += v[x];
        x -= x & (-x);
    }
    return sum;
}

void update(int ind, int val) {
    while (ind <= mx) {
        v[ind] += val;
        ind += ind & (-ind);
    }
}

int main() {
    int n, l, r, ind, val;
    cin >> n >> l >> r >> ind >> val;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        update(i, num);
    }

    int p = bit(r) - bit(l - 1); // Note: Changed bit(l) to bit(l - 1) for inclusive range
    cout << p << endl;

    update(ind, val);

    int q = bit(r) - bit(l - 1); // Recalculate after update
    cout << q << endl;

    return 0;
}
