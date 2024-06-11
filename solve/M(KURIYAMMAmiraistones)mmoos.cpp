#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
#define int long long
int n,m;
long long ans,ans1;
long long c[N];
long long answers[N];
long long  block;
long long  arr[N];
int arr1[N];
pair< pair<int, int>, pair<int,int> >queries[N];
inline void add(int x)
{
    ans+=arr[x];
    ans1+=arr1[x];
}

inline void remove(int x)
{
    ans-=arr[x];
    ans1-=arr1[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    block= static_cast<int>(sqrt(N));
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    sort(arr1+1,arr1+(n+1));
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>queries[i].second.second;
        cin>>queries[i].first.first >> queries[i].first.second;
        queries[i].second.first=i;
    }

    sort(queries, queries + m);

    int mo_left = queries[0].first.first, mo_right = queries[0].first.first;
    ans=arr[mo_left];
    ans1=arr1[mo_left];

    for(int i = 0; i < m; i++) {
        int left = queries[i].first.first;
        int right = queries[i].first.second;
        while(mo_right < right) {
            mo_right++;
            add(mo_right);
        }
        while(mo_right > right) {
            remove(mo_right);
            mo_right--;
        }

        while(mo_left < left) {
            remove(mo_left);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(mo_left);
        }
        if(queries[i].second.second==1){
            answers[queries[i].second.first] =ans;
        }
        else
           answers[queries[i].second.first] = ans1;
    }
    for(int i = 0; i < m; i++)
        cout << answers[i] << "\n";

    return 0;
}
