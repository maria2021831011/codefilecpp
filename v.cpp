#include<bits/stdc++.h>
using namespace std;
vector<int>create(string pattern)
{
    vector<int>lsp(pattern.size());
    int index=0;
    for(int i=1;i<pattern.size();++i)
    {
        if(pattern[index]==pattern[i])
        {
           lsp[i]=index+1;
           ++index;
           ++i;
        }else
        {
            if(index!=0)
            {
                index=lsp[index-1];

            }else
            {
                lsp[i]=index;
                ++i;
            }
        }
    }
    return lsp;
}
void kmp(string text,string pattern)
{ vector<int>lps=create(pattern);
bool found=false;
int i=0;int j=0;
while(i<text.size())
{

    if(text[i]==pattern[j])
    {
        ++i;
        ++j;

    }else
    {
        if(j!=0)
        {
            j=lps[j-1];
        }else
        {
            ++i;
        }
    }
    if(j==pattern.size())
    {
        found=true;
        cout<<"found"<<endl;cout<<i-pattern.size()<<endl;
        j=lps[j-1];
    }
}if(!found)
{
    cout<<"no"<<endl;
}



}
int main()
{ ios_base::sync_with_stdio(false);
cin.tie(NULL);

    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    kmp(text,pattern);
}
