
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Sorting the pairs
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        // Checking for intersection
        if ((a < c && c < b) || (a < d && d < b)) {if((a < c && c < b) && (a < d && d < b))
            {
                cout<<"NO"<<endl;
            }else{
            cout << "YES" << endl;
        }} else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
