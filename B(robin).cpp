#include<bits/stdc++.h>
using namespace std;
int a[100005];
int tr[100005];
int bitq(int in)
{
    int s=0;
    while(in>0)
    {
        s+=tr[in];
        in-=(in&(-in));
    }return s;
}
void bitu(int n,int in,int v)
{
    while(in<=n)
    {tr[in]+=v;
    in+=(in&(-in));
    }
}
void bitb(int n)
{
    for(int i=1;i<=n;i++)
    {
        bitu(n,i,a[i]);
    }
}
int main()
{
    int t,i=0;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        tr[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            tr[i]=0;
        }
        bitb(n);
        cout<<"Case "<<++i<<":"<<endl;
        while(q--)
        {
            int l,r,ca;
            cin>>ca;
            if(ca==1)
            {
                cin>>l;
                int v=a[l+1];
                a[l+1]=0;
                cout<<v<<endl;
                bitu(n,l+1,-v);
            }else if(ca==3)
            {
                cin>>l>>r;
                int v=bitq(r+1)-bitq(l);
                cout<<v<<endl;
            }
            else
            {
                int v,l;
                cin>>l>>v;
                a[l+1]+=v;
                bitu(n,l+1,v);
            }
        }
    }
}

