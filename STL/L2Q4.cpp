#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int x;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        s += x;
    }
    cout << s << "\n";
    for (auto y = v.rbegin(); y != v.rend(); y++) {
        cout << *y << " ";
    }
}