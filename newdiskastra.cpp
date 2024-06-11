#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int result = n;
        for (int len = 1; len <= n; ++len) {
            bool valid = true;
            for (int i = 0; i < len; ++i) {
                char ch = s[i];
                for (int j = i + len; j < n; j += len) {
                    if (s[j] != ch) {
                        if (j + len < n && s[j + len] == ch) {
                            ++j;
                            continue;
                        }
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (valid) {
                result = len;
                break;
            }
        }
        cout << result << endl;
    }

    return 0;
}
