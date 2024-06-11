#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int visited[9] = {0};

int main() {
    int non = 9;
    int s_node = 0;

    int graph[9][9] = {
        {0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    s.push(s_node);
    visited[s_node] = 1;

    while (!s.empty()) {
        int current = s.top();
        cout << "current: " << current << endl;
        s.pop();

        for (int i = 0; i < non; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                s.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
