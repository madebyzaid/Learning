#include <bits/stdc++.h>
#include <utils.h>
using namespace std;

void remove_negatives(list<int>& l) {
    for(auto t = l.begin(); t != l.end();) {
        if (*t < 0) {
            t = l.erase(t);
        }
        else {
            t++;
        }
    }
}

int main() {
    list<int> m = {1, 2, -99, 3,  4, -1, 5, -5, -8, };
    remove_negatives(m);
    printlist("m", m);
    return 0;
}