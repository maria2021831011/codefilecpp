#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    cout<<"len"<<endl;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p=0;



    for(i=0;i<n-1;i++)
    {bool flag=0;
    p++;

        cout<<"after p pass"<<p<<endl;
        for(j=0;j<(n-1)-i;j++)
        {
            if(a[j]>a[j+1])
            {
                 flag=1;
                swap(a[j],a[j+1]);
            }
            for(k=0;k<n;k++)
            {
                cout<<a[k]<<" ";
            }cout<<endl;
        }

        if(!flag)
        {
            break;
        }
    }

}
