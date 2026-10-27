#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                x = x ^ i;
                y = y ^ j;
            }
        }
    }
    cout << x + 1 << " " << y + 1;
    return 0;
}