#include <iostream>

using namespace std;

int main() {
    int m;
    int n;
    cin >> m >> n;

    int Multi_Dimension_Array[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Multi_Dimension_Array[i][j] = (i * 10) + j;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << Multi_Dimension_Array[i][j] << " ";
        }
        cout << '\n';
    }

    return (0);
}