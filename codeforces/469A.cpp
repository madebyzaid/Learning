#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<int> s;
    int p; cin >> p;
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    int q; cin >> q;
    for (int j = 0; j < q; j++) {
        int y; cin >> y;
        s.insert(y);
    }
    if ((int)s.size() == n) {
        cout << "I become the guy.\n";
    } else {
        cout << "Oh, my keyboard!\n";
    }
    return 0;
}