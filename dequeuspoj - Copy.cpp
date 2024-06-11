
#include <bits/stdc++.h>
using namespace std;

int block;
struct query
{
    int l, r;
};

bool compare(query x, query y)
{
    if (x.l / block != y.l / block)
        return x.l / block < y.l / block;

    return x.r < y.r;
}

void queryResults(int v[], int n, query q[], int m)
{
    block = (int)sqrt(n);
    sort(q, q + m, compare);

    int currL = 0, currR = 0;
    unordered_map<int, int> freqMap;
    for (int i = 0; i < m; i++)
    {
        int L = q[i].l, R = q[i].r;
        while (currL < L)
        {
            freqMap[v[currL]]--;
            currL++;
        }
        while (currL > L)
        {
            currL--;
            freqMap[v[currL]]++;
        }
        while (currR <= R)
        {
            freqMap[v[currR]]++;
            currR++;
        }
        while (currR > R + 1)
        {
            currR--;
            freqMap[v[currR]]--;
        }

        cout << "Frequency count of elements in range [" << L << ", " << R << "]" << endl;
        for (auto &pair : freqMap)
        { if(pair.second>0)
            cout << pair.first << ": " << pair.second << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int v[n+1];

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    query q[m];
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].l >> q[i].r;
    }
    queryResults(v, n, q, m);

    return 0;
}
