#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    int lb;
    int up;
    int mid;
    lb=0;
    up=n-1;
    char s;
    int p=0;
    cin>>s;
    while(lb<=up)
    {
        mid=(lb+up)/2;
        if(a[mid]==s)
        {
            cout<<"data at found at index"<<mid<<endl;
            p=1;
            break;
        }
        else if(a[mid]<s)
        {
            lb=mid+1;
        }
        else if(a[mid]>s)
        {
            up=mid-1;
        }
    }
        if(p==0)
        {
            cout<<"data not found"<<endl;
        }


}
