#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int findPeriod(const string& str) {
    int n = str.length();
    vector<int> lps = computeLPS(str);
    int period = n - lps[n - 1];
    if (n % period == 0)
        return period;
    else
        return n;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string no;
        getline(cin, no);

        string str;
        getline(cin, str);

        str = str.substr(0, 80);

        int period = findPeriod(str);
        cout << period << endl;

        if (T > 0)
            cout << endl;
    }

    return 0;
}
