#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int mex(unordered_set<int>s)
{
    int mex=0;
    while(s.find(mex)!=s.end())

        mex++;

    return mex;
}

int grundy(int k,int g[])
{
g[0]=0;
    if(g[k]!=-1)
    {
        return g[k];
    }unordered_set<int>s;
    for(int i=1;i<=3;i++)

        s.insert(grundy(k-i,g));
        g[k]=mex(s);
        return g[k];

}
void winner(int t,int g[],int n)
{
    int sum=g[v[0]];
    for(int i=1;i<n;i++)
    {
        sum^=g[v[i]];
    }if(sum!=0)
    {
        if (t == 1) {
            cout << "1st player" << endl;
        } else {
            cout << "2nd player" << endl;
        }
    } else {
        if (t == 1) {
            cout << "2nd player" << endl;
        } else {
            cout << "1st player" << endl;
        }
    }
}



int main()
{int n;
cin>>n;
v.resize(n);
for(int i=0;i<n;i++)
{
    cin>>v[i];
}
int maximum=*max_element(v.begin(),v.end());
int g[maximum+1];
 memset(g, -1, sizeof(g));
for(int i=0;i<n;i++)
{
    grundy(v[i],g);
}
winner(1,g,n);

}
