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
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;
            if(s.size()!=n)
            {
                cout<<"NO"<<endl;
                continue;
            }
            map<char,vector<int>>m1;
            bool ok=true;
            for(int i=0;i<s.size();i++)
            {
                m1[s[i]].push_back(i);
            }for( auto it:m1)
            {
                for(int i=0;i<it.second.size()-1;i++)
                {
                    if(a[it.second[i]]!=a[it.second[i+1]])
                    {
                        ok=false;
                    }
                }
            }
            if(!ok)
            {
                cout<<"NO"<<endl;
                continue;

            }
             map<int,vector<int>>m2;

            for(int i=0;i<n;i++)
            {
                m2[a[i]].push_back(i);
            }for(auto it:m2)
            {
                for(int i=0;i<it.second.size()-1;i++)
                {
                    if(s[it.second[i]]!=s[it.second[i+1]])
                    {
                        ok=false;
                    }
                }
            }
            if(!ok)
            {
                cout<<"NO"<<endl;


            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
}
