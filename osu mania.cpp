


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
       string s;
       vector<int>v;
       for(int i=0;i<n;i++)
       {
           cin>>s;
           for(int j=0;j<4;j++)
           {if(s[j]=='#')
           {
               v.push_back(j+1);
           }

           }
       }


        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}































































































































































































































































































































































































































































































































































































