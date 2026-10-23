#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

int main() {

    // CREATING PAIRS
    // pair<datatype1, datatype2> variable_name;

    pair<int, int> p;
    printpair("p", p); // p = {0, 0}

    pair<int, string> q = {1, "hi"};
    printpair("q", q); // q = {1, hi}

    pair<int, int> r(3, 4); // {3,4}
    printpair("r", r);

    pair<int, pair<int, int>> s = {1, {3, 7}};
    printpair("s", s); // s = {1, {3, 7}}

    pair<int, int> t = make_pair(5, 6);
    printpair("t", t);

    // datatype array_name[] creates an array
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    // MODIFYING A PAIR
    p.first -= 10;
    p.second += 5;
    printpair("p", p);

    cout << "p.first = "; cin >> p.first;
    cout << "p.second = "; cin >> p.second;
    printpair("p", p);

    // Swapping contents of pairs
    pair<int, int> a = {1, 9}, b = {3, 4};
    swap(a, b); // or a.swap(b)
    printpair("a", a);
    printpair("b", b);

    // Lexicographic comparison (==, !=, <, <=, >, >=)
    cout << (a < b) << "\n"; // True
    cout << (pair<int, int>{3, 0} < pair<int, int>{3, 9}) << "\n"; // True

    // Unpacking pair
    auto [x, y] = p;
    cout << "x = " << x << "\n" << "y = " << y << "\n";

    return 0;
}