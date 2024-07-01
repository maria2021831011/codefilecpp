
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> index;          
    map<int, string> index2;         
    vector<int> depends[110];        
    map<int, int> indegree;         
    vector<int> result;             
    int num, match, indx, cs = 1;

    while (cin >> num) {
        index.clear();
        index2.clear();
        indegree.clear();
        result.clear();
        for (int i = 0; i < 110; ++i) {
            depends[i].clear();
        }

        indx = 0;
        for (int i = 1; i <= num; ++i) {
            string s;
            cin >> s;
            index[s] = ++indx;
            index2[indx] = s;
        }

        cin >> match;
        for (int i = 0; i < match; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            indegree[index[s2]]++;
            depends[index[s1]].push_back(index[s2]);
        }

        
        for (int i = 1; i <= num; ++i) {
            for (int j = 1; j <= num; ++j) {
                if (indegree[j] == 0) {
                    result.push_back(j);
                    indegree[j] = -1; 
                    for (int k : depends[j]) {
                        indegree[k]--;
                    }
                    break;
                }
            }
        }

        cout << "Case #" << cs << ": Dilbert should drink beverages in this order: ";
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << index2[result[i]];
        }
        cout << "." << endl << endl;
        cs++;
    }

    return 0;
}
