#include <bits/stdc++.h>
#include "mylib/utils.h"
using namespace std;

int main() {
    // priority_queue = a heap, the top is always the LARGEST element by default
    // you only see the top. no indexing, no iterators, no range-for, no clear()
    // push and pop are O(log n), top is O(1)

    // CREATION

    // general syntax: priority_queue<TYPE, CONTAINER, COMPARATOR> name;
    // TYPE: type of the elements
    // CONTAINER: what it stores them in (almost always vector<TYPE>)
    // COMPARATOR: decides which element goes on top (default is less<TYPE>)

    // max-heap (default): top is the largest
    priority_queue<int> a;
    a.push(5); a.push(2); a.push(8); a.push(4);
    printpq("a", a); // {8, 5, 4, 2}, listed in pop order, top first

    // min-heap: top is the smallest, you have to write all three arguments
    priority_queue<int, vector<int>, greater<int>> b;
    b.push(5); b.push(2); b.push(8); b.push(4);
    printpq("b", b); // {2, 4, 5, 8}

    // priority_queue<int> pq = {1, 2, 3}; is NOT valid, there is no initializer-list constructor

    priority_queue<int> c(a); // copy of a
    printpq("c", c);

    priority_queue<int> d = a; // copy of a
    printpq("d", d);

    // from a range of another container, O(n)
    vector<int> v = {3, 1, 9, 7};
    priority_queue<int> e(v.begin(), v.end()); // max-heap
    printpq("e", e); // {9, 7, 3, 1}

    priority_queue<int, vector<int>, greater<int>> f(v.begin(), v.end()); // min-heap
    printpq("f", f); // {1, 3, 7, 9}

    cout << "\n";

    // METHODS

    // Adding

    priority_queue<int> g;
    g.push(10);
    g.push(30);
    g.push(20);
    printpq("g", g); // {30, 20, 10}, insertion order doesn't matter

    g.emplace(40);
    printpq("g", g); // {40, 30, 20, 10}

    cout << "\n";

    // Accessing the top

    cout << "g.top() = " << g.top() << "\n"; // 40

    // top() returns a CONST reference, so g.top() = 5; won't compile
    // (unlike stack, you cannot modify the top in place)

    cout << "\n";

    // Removing

    // g.pop(); removes the top and returns NOTHING (void)
    g.pop();
    printpq("g", g); // {30, 20, 10}

    // int x = g.pop(); won't compile
    // to use the value, read it with top() first, then pop
    int x = g.top(); // 30
    g.pop();
    printpq("g", g); // {20, 10}
    cout << "popped value = " << x << "\n";

    cout << "\n";

    // size and empty

    cout << "g.size() = " << g.size() << "\n"; // 2
    cout << "g.empty() = " << g.empty() << "\n"; // 0

    // top() and pop() on an EMPTY priority queue are undefined behavior
    // always check !g.empty() first

    cout << "\n";

    // Others

    // swap(h, i); or swap(i, h); or h.swap(i); or i.swap(h);
    priority_queue<int> h, i;
    h.push(1);
    i.push(7); i.push(8);
    swap(h, i);
    printpq("h", h); // {8, 7}
    printpq("i", i); // {1}

    // there is no clear(), so assign an empty priority queue
    h = priority_queue<int>();
    printpq("h", h); // {}

    cout << "\n";

    // PAIRS

    // pairs are compared by first, then second only if the firsts are equal
    priority_queue<pair<int, int>> m; // max-heap of pairs
    m.push({1, 5});
    m.push({3, 2});
    m.push({3, 7});
    m.emplace(2, 9);

    cout << "max-heap of pairs, popping: ";
    while (!m.empty()) {
        cout << "{" << m.top().first << ", " << m.top().second << "} ";
        m.pop();
    } // {3, 7} {3, 2} {2, 9} {1, 5}
    cout << "\n";

    // min-heap of pairs, you have to write all three arguments
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> n;
    n.push({1, 5});
    n.push({3, 2});
    n.push({3, 7});
    n.emplace(2, 9);

    cout << "min-heap of pairs, popping: ";
    while (!n.empty()) {
        cout << "{" << n.top().first << ", " << n.top().second << "} ";
        n.pop();
    } // {1, 5} {2, 9} {3, 2} {3, 7}
    cout << "\n";

    cout << "\n";

    // ITERATORS
    /*
    none. no begin(), end(), rbegin(), rend() and no pq[i].
    range-for doesn't work either.
    you can only see the top. the elements are NOT stored in sorted order,
    only the top is guaranteed to be the largest (or smallest for a min-heap).
    */

    // LOOPING

    // the only way to visit every element is to pop them one by one
    // this DESTROYS the priority queue, and elements come out in sorted order
    priority_queue<int> j;
    j.push(4); j.push(9); j.push(1); j.push(6);
    printpq("j", j);

    cout << "Popping everything: ";
    while (!j.empty()) {
        cout << j.top() << " ";
        j.pop();
    } // prints 9 6 4 1 (descending for a max-heap)
    cout << "\n";
    printpq("j", j); // {}

    // to look at everything without losing it, loop over a copy
    priority_queue<int> k;
    k.push(4); k.push(9); k.push(1);
    priority_queue<int> temp = k;
    cout << "Looping over a copy: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    } // prints 9 4 1
    cout << "\n";
    printpq("k", k); // {9, 4, 1} k is untouched

    /*
    complexity:
    push, emplace, pop: O(log n)
    top, size, empty, swap: O(1)
    building from a range of n elements: O(n)
    copying: O(n)
    */

    cout << "\n";
    return 0;
}