

#include <bits/stdc++.h>
using namespace std;
int pi[1000005];
string p;
void computePrefixFunction() {
    int now = -1;
    pi[0] = now;

    for (int i = 1; i < p.length(); i++) {
        while (now != -1 && p[i] != p[now + 1])
            now = pi[now];

        if (p[i] == p[now + 1])
            pi[i] = ++now;
        else
            pi[i] = -1;
    }
}

int main() {
    cin >> p;
    computePrefixFunction();
    int len = p.length();
    int maxi = pi[len - 1];
    int found = -1;
    if (maxi != -1) {

        found = pi[maxi];
        for (int i = 1; i < len - 1; i++) {
            if (pi[i] == maxi)
                found = maxi;
        }
    }

    if (found == -1)
        cout << "Just a legend" << endl;
    else
        cout << p.substr(0, found + 1) << endl;

    return 0;
}
