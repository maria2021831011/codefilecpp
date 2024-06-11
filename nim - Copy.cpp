
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int calnim(int n) {
    int sum = v[0];
    for (int i = 1; i < n; i++) {
        sum = sum ^ v[i];
    }
    return sum;
}

void winner(int n, int turn) {
    if (calnim(n) != 0) {
        if (turn == 1) {
            cout << "computer" << endl;
        } else {
            cout << "human" << endl;
        }
    } else {
        if (turn == 1) {
            cout << "human" << endl;
        } else {
            cout << "computer" << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    winner(n, 1); // Assuming computer starts the game
    return 0;
}
