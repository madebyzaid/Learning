#include <bits/stdc++.h>
#include "mylib/utils.h"
using namespace std;

int main() {
    // stack = LIFO (last in, first out)
    // you only ever touch the top: push, top, pop
    // no indexing, no iterators, no range-for, no clear()

    // CREATION

    stack<int> a; // empty stack
    printstack("a", a);

    a.push(10); a.push(20); a.push(30);
    printstack("a", a); // {10, 20, 30}, top is 30

    // stack<int> s = {1, 2, 3}; is NOT valid
    // there is no initializer-list constructor
    // you create it empty and push each value

    stack<int> b(a); // copy of a
    printstack("b", b);

    stack<int> c = a; // copy of a
    printstack("c", c);

    stack<int> d(deque<int>{1, 2, 3});
    // built from a container, last element becomes the top
    printstack("d", d); // {1, 2, 3}, top is 3

    stack<pair<int, int>> m; // stack of pairs

    cout << "\n";

    // METHODS

    // Adding

    stack<int> e;
    e.push(10);
    e.push(20);
    e.push(30);
    printstack("e", e); // {10, 20, 30}

    e.push(40);
    e.emplace(50);
    printstack("e", e); // {10, 20, 30, 40, 50}

    m.push({1, 2}); // adds an already constructed pair
    m.emplace(3, 4); // hands 3 and 4 to the pair constructor
    // m.emplace({5, 6}); won't work, same reason as emplace_back on a vector
    // m = {{1, 2}, {3, 4}}, top is {3, 4}

    cout << "\n";

    // Accessing the top

    cout << "e.top() = " << e.top() << "\n"; // 50

    e.top() = 99; // top() returns a reference, so this changes the top element
    printstack("e", e); // {10, 20, 30, 40, 99}

    cout << "m.top() = {" << m.top().first << ", " << m.top().second << "}\n"; // {3, 4}
    m.top().second += 10; // top is now {3, 14}
    cout << "m.top() = {" << m.top().first << ", " << m.top().second << "}\n";

    cout << "\n";

    // Removing

    // e.pop(); removes the top and returns NOTHING (void)
    e.pop();
    printstack("e", e); // {10, 20, 30, 40}

    // int x = e.pop(); won't compile
    // to use the value, read it with top() first, then pop
    int x = e.top(); // 40
    e.pop();
    printstack("e", e); // {10, 20, 30}
    cout << "popped value = " << x << "\n";

    cout << "\n";

    // size and empty

    cout << "e.size() = " << e.size() << "\n"; // 3
    cout << "e.empty() = " << e.empty() << "\n"; // 0

    // top() and pop() on an EMPTY stack are undefined behavior
    // always check !e.empty() first

    cout << "\n";

    // Others

    // swap(f, g); or swap(g, f); or f.swap(g); or g.swap(f);
    stack<int> f, g;
    f.push(1);
    g.push(7); g.push(8);
    swap(f, g);
    printstack("f", f); // {7, 8}
    printstack("g", g); // {1}

    // there is no clear(), so assign an empty stack
    f = stack<int>();
    printstack("f", f); // {}

    cout << "\n";

    // ITERATORS
    /*
    none. no begin(), end(), rbegin(), rend() and no s[i].
    range-for doesn't work either.
    you can only see the top.
    */

    // LOOPING

    // the only way to visit every element is to pop them one by one
    // this DESTROYS the stack, and elements come out top to bottom
    stack<int> h;
    h.push(10); h.push(20); h.push(30);
    printstack("h", h);

    cout << "Popping everything: ";
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    } // prints 30 20 10
    cout << "\n";
    printstack("h", h); // {} the stack is now empty

    // to look at everything without losing the stack, loop over a copy
    stack<int> k;
    k.push(1); k.push(2); k.push(3);
    stack<int> temp = k;
    cout << "Looping over a copy: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    } // prints 3 2 1
    cout << "\n";
    printstack("k", k); // {1, 2, 3} k is untouched

    /*
    for a stack<pair<int, int>>, top() gives the pair itself:
    s.top().first
    s.top().second
    (no arrow needed, you are not using an iterator)
    */

    cout << "\n";
    return 0;
}