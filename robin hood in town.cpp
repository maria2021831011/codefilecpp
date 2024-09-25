
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> job_days(n + 1, 0); // to store how many jobs are happening on each day

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        job_days[l]++;     // mark the start of a job
        if (r + 1 <= n) job_days[r + 1]--; // mark the end of a job
    }

    // Step 1: Compute the number of jobs happening each day using prefix sums
    for (int i = 1; i <= n; i++) {
        job_days[i] += job_days[i - 1];
    }

    // Step 2: Use a sliding window of size d to find the max/min job overlap
    int current_overlap = 0;
    for (int i = 1; i <= d; i++) {
        current_overlap += job_days[i];
    }

    int max_overlap = current_overlap;
    int min_overlap = current_overlap;
    int best_start_brother = 1; // max overlap start day
    int best_start_mother = 1;  // min overlap start day

    for (int i = 2; i <= n - d + 1; i++) {
        current_overlap = current_overlap - job_days[i - 1] + job_days[i + d - 1];
        if (current_overlap > max_overlap) {
            max_overlap = current_overlap;
            best_start_brother = i;
        }
        if (current_overlap < min_overlap) {
            min_overlap = current_overlap;
            best_start_mother = i;
        }
    }

    cout << best_start_brother << " " << best_start_mother << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
