#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> L;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            L.push_front(x);
        }
        else {
            L.push_back(x);
        }
    }
    for (int k : L) {
        cout << k << " ";
    }
    cout << "\n";
    for (auto t = L.rbegin(); t != L.rend(); t++) {
        cout << *t << " ";
    }

    return 0;
}