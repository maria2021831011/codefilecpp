
#include<bits/stdc++.h>
using namespace std;
const int alpha=25;
struct trienode
{struct trienode*children[alpha];
    bool isend;
};
struct trienode*getnode()
{
    struct trienode*pnew=new trienode;
    pnew->isend=false;
    for(int i=0;i<alpha;i++)
    {
        pnew->children[i]=NULL;
    }
    return pnew;

}
void insertt(struct trienode*root,string s)
{
    struct trienode*pnew=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(!pnew->children[index])
            pnew->children[index]=getnode();
        pnew=pnew->children[index];
    }
    pnew->isend=true;
}
bool searchh(struct trienode*root,string s)
{
    struct trienode*pnew=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(!pnew->children[index])
            return false;
        pnew=pnew->children[index];
    }
    return(pnew->isend);
}

int main()
{
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    struct trienode *root=getnode();
    for(int i=0;i<n;i++)
    {
        insertt(root,s[i]);
    }
    cout<<searchh(root ,s1);
}
