#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int x, y, z;
        cin >> x >> y >> z;

        // Check if all variables are zero
        if(x == 0 && y == 0 && z == 0) {
            cout << "0" << endl;
            continue;
        }

        // Check if y and z are zero
        if(y == 0 && z == 0) {
            cout << x << endl;
            continue;
        }

        // Check if x and z are zero
        if(x == 0 && z == 0) {
            if(y % 3 == 0)
                cout << y / 3 << endl;
            else
                cout << y / 3 + 1 << endl;
            continue;
        }

        // Check if x and y are zero
        if(x == 0 && y == 0) {
            if(z % 3 == 0)
                cout << z / 3 << endl;
            else
                cout << z / 3 + 1 << endl;
            continue;
        }

        // Calculate minimum number of tents
        int p = y % 3;
        int f = y / 3;

        // Check if it's possible to accommodate participants
        if(p % 3 != 0 && 3 - p > z) {
            cout << "-1" << endl;
            continue;
        } else {
            z -= 3 - p;
            if(z % 3 == 0)
                z = z / 3;
            else
                z = z / 3 + 1;

            // Output the minimum number of tents needed
            if(p == 0)
                cout << x + f + z << endl;
            else
                cout << x + f + 1 + z << endl;
        }
    }

    return 0;
}

