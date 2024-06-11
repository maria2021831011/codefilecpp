







#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, m1, n1, i, j, k,sum=0;

    cout << "Enter row col A matrix:" << endl;
    cin >> n >> m;

    cout << "Enter row col B matrix:" << endl;
    cin >> n1 >> m1;

    int a[n][m], b[n1][m1], c[10][10];

    if (m != n1) {
        cout << "Error: Incompatible matrices for multiplication." << endl;
    } else {
        cout << "Enter elements for matrix A:" << endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        cout << "Enter elements for matrix B:" << endl;
        for (i = 0; i < n1; i++) {
            for (j = 0; j < m1; j++) {
                cin >> b[i][j];
            }
        }


        // Matrix multiplication
        for (i = 0; i < n; i++) {
            for (j = 0; j < m1; j++) {
                for (k = 0; k < m; k++) {
                    c[i][j]=sum + a[i][k] * b[k][j];
                }
            }
        }

        // Display the result matrix
        cout << "Resultant matrix:" << endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m1; j++) {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}





