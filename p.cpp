#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());



    return 0;
}
