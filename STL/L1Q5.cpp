#include <bits/stdc++.h>
using namespace std;

pair<int, int> min_max(int a, int b, int c) {

    int max = a;

    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    int min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }

    return pair<int, int> {min, max};

}

int main() {

    int x, y, z;
    cin >> x >> y >> z;
    pair<int, int> p = min_max(x, y, z);
    cout << p.first << p.second;

    return 0;

}