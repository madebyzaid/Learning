#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "n = "; cin >> n;
    pair<int, int> p, m;
    for (int i = 0; i < n; i++) {
        cout << "Pair = "; cin >> p.first >> p.second;
        if (i == 0 || p.second > m.second) {
            m = p;
        }
    }
    cout << "Pair with largest second integer = " << m.first << " " << m.second << "\n";

    return 0;

}