#include <bits/stdc++.h>
using namespace std;

void remove_evens(vector<int> &v) {
    vector<int> z;
    for (int x : v) {
        if (x % 2 != 0) {
            z.push_back(x);
        }
    }
    v = z;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    remove_evens(a);
    for (int x : a) {
    cout << x << " ";
    }
    return 0;
}