#include<bits/stdc++.h>
using namespace std;

int main() {int t;
cin>>t;
while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<char> v;
    char prev = '1';


    for (char c : s) {
        if (c == '1') {
            v.push_back(c);
        } else if (c == '0' && prev == '1') {
            v.push_back(c);
        }
        prev = c;
    }

    int o = 0, z = 0;


    for (char c : v) {
        if (c == '1') {
            o++;
        } else if (c == '0') {
            z++;
        }
    }


    if (o > z) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
    return 0;
}


