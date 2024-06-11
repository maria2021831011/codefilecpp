#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int m;
        cin >> m;
        vector<int> d(m);
        for (int i = 0; i < m; ++i) cin >> d[i];

        unordered_map<int, int> needed_changes;
        unordered_map<int, int> available_changes;

        // Calculate the needed changes
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                needed_changes[b[i]]++;
            }
        }

        // Count available modifications
        for (int i = 0; i < m; ++i) {
            available_changes[d[i]]++;
        }

        // Check if we can fulfill the needed changes
        bool possible = true;
        for (const auto& change : needed_changes) {
            if (available_changes[change.first] < change.second) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
