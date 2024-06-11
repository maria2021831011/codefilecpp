
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
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

}
