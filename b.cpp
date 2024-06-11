
#include <bits/stdc++.h>
using namespace std;
int block;
struct query
{
    int l,r;
};
bool compare(query x, query y)
{

    if (x.l/block!=y.l/block)
        return x.l/block < y.l/block;


    return x.r < y.r;
}

void queryResults(int v[], int n, query q[], int m)
{
    block = (int)sqrt(n);
    sort(q, q + m, compare);

    int currL = 0, currR = 0;
    int currSum = 0;
    for (int i=0; i<m; i++)
    {
        int L = q[i].l, R = q[i].r;
        while(currL<L)
        {
            currSum-=v[currL];
            currL++;
        }
        while (currL > L)
        {
            currSum += v[currL-1];
            currL--;
        }
        while (currR <= R)
        {
            currSum += v[currR];
            currR++;
        }
        while (currR > R+1)
        {
            currSum -= v[currR-1];
            currR--;
        }


        cout << "Sum of [" << L << ", " << R
             << "] is "  << currSum << endl;
    }
}
int main()
{
    int n,m;
cin>>n>>m;
int v[n];

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    query q[m];
    for(int i=0;i<m;i++)
    {
        cin>>q[i].l>>q[i].r;
    }
    queryResults(v,n,q,m);

    return 0;
}
