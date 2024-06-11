
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,sum=0,m,n,m1,n1;
    cin>>m>>n;
    cin>>m1>>n1;
    int a[m][n],b[m1][n1],c[10][10];
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cin>>a[i][j];
            }
        }
         for (i = 0; i < m1; i++) {
            for (j = 0; j < n1; j++) {
                cin>>b[i][j];
            }
        }
         for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
            c[i][j]=sum+a[i][j]+b[i][j];
            }
        }
         for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
}
