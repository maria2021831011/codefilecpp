

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> arr2;
void build(int node, int Begin, int End)
{

    if(Begin == End)
    {
        arr2[node] = arr[Begin];
        return;
    }

    int Left, Right, Mid;
    Left = node*2;
    Right = (node*2)+1;
    Mid = Begin+((End-Begin)/2);
    build(Left, Begin, Mid);
    build(Right, Mid+1, End);
    arr2[node] = min(arr2[Left], arr2[Right]);
}

int query(int node, int Begin, int End, int I, int J)
{
    if(End<I || J<Begin)
        return INT_MAX;
    if(I<=Begin && End<=J)
        return arr2[node];
    int Left, Right, Mid, q1, q2;
    Left = node*2;
    Right = (node*2)+1;
    Mid = Begin+((End-Begin)/2);
    q1 = query(Left, Begin, Mid, I, J);
    q2 = query(Right, Mid+1, End, I, J);
    return min(q1, q2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        int n, q;
        cin>>n>>q;
        arr.assign(n+2, 0);
        arr2.assign((4*n)+2, 0);

        for(int i=1; i<=n; i++)
            cin>>arr[i];

        build(1, 1, n);
        cout<<"Case "<<cs<<":"<<"\n";
        for(int i=1; i<=q; i++)
        {
            int I, J;
            cin>>I>>J;
            cout<<query(1, 1, n, I, J)<<"\n";
        }
    }

    return 0;
}
