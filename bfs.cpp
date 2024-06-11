#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int visited[9] = {0};

int main() {
    int non = 9;
    int source_node = 0;

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

    q.push(source_node);
    visited[source_node] = 1;

    while (!q.empty()) {
        int current = q.front();
        cout << "current: " << current << endl;
        q.pop();

        for (int i = 0; i < non; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
