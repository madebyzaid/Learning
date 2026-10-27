#include <bits/stdc++.h>
#include "mylib/utils.h"
using namespace std;

int main() {
    // queue = FIFO (first in, first out)
    // push at the back, remove from the front
    // you can peek at both ends: front() and back()
    // no indexing, no iterators, no range-for, no clear()

    // CREATION

    queue<int> a; // empty queue
    printqueue("a", a);

    a.push(10); a.push(20); a.push(30);
    printqueue("a", a); // {10, 20, 30}, front is 10, back is 30

    // queue<int> q = {1, 2, 3}; is NOT valid, there is no initializer-list constructor
    // you create it empty and push each value

    queue<int> b(a); // copy of a
    printqueue("b", b);

    queue<int> c = a; // copy of a
    printqueue("c", c);

    queue<int> d(deque<int>{1, 2, 3}); // built from a container, its first element becomes the front
    printqueue("d", d); // {1, 2, 3}, front is 1

    queue<pair<int, int>> m; // queue of pairs

    cout << "\n";

    // METHODS

    // Adding (always at the back)

    queue<int> e;
    e.push(10);
    e.push(20);
    e.push(30);
    printqueue("e", e); // {10, 20, 30}

    e.push(40);
    e.emplace(50);
    printqueue("e", e); // {10, 20, 30, 40, 50}

    m.push({1, 2}); // adds an already constructed pair
    m.emplace(3, 4); // hands 3 and 4 to the pair constructor
    // m.emplace({5, 6}); won't work, same reason as emplace_back on a vector
    // m = {{1, 2}, {3, 4}}, front is {1, 2}, back is {3, 4}

    cout << "\n";

    // Accessing both ends

    cout << "e.front() = " << e.front() << "\n"; // 10
    cout << "e.back() = " << e.back() << "\n"; // 50

    // front() and back() return references, so you can modify the elements
    e.front() = 99;
    e.back() = 77;
    printqueue("e", e); // {99, 20, 30, 40, 77}

    cout << "m.front() = {" << m.front().first << ", " << m.front().second << "}\n"; // {1, 2}
    cout << "m.back() = {" << m.back().first << ", " << m.back().second << "}\n"; // {3, 4}

    // there is no queue[i] and no way to read the middle without popping

    cout << "\n";

    // Removing (always from the front)

    // e.pop(); removes the front and returns NOTHING (void)
    e.pop();
    printqueue("e", e); // {20, 30, 40, 77}

    // int x = e.pop(); won't compile
    // to use the value, read it with front() first, then pop
    int x = e.front(); // 20
    e.pop();
    printqueue("e", e); // {30, 40, 77}
    cout << "popped value = " << x << "\n";

    cout << "\n";

    // size and empty

    cout << "e.size() = " << e.size() << "\n"; // 3
    cout << "e.empty() = " << e.empty() << "\n"; // 0

    // front(), back() and pop() on an EMPTY queue are undefined behavior
    // always check !e.empty() first

    cout << "\n";

    // Others

    // swap(f, g); or swap(g, f); or f.swap(g); or g.swap(f);
    queue<int> f, g;
    f.push(1);
    g.push(7); g.push(8);
    swap(f, g);
    printqueue("f", f); // {7, 8}
    printqueue("g", g); // {1}

    // there is no clear(), so assign an empty queue
    f = queue<int>();
    printqueue("f", f); // {}

    cout << "\n";

    // ITERATORS
    /*
    none. no begin(), end(), rbegin(), rend() and no q[i].
    range-for doesn't work either.
    you can only see the front and the back.
    */

    // LOOPING

    // the only way to visit every element is to pop them one by one
    // this DESTROYS the queue, and elements come out front to back
    queue<int> h;
    h.push(10); h.push(20); h.push(30);
    printqueue("h", h);

    cout << "Popping everything: ";
    while (!h.empty()) {
        cout << h.front() << " ";
        h.pop();
    } // prints 10 20 30 (same order they went in, unlike a stack)
    cout << "\n";
    printqueue("h", h); // {} the queue is now empty

    // to look at everything without losing the queue, loop over a copy
    queue<int> k;
    k.push(1); k.push(2); k.push(3);
    queue<int> temp = k;
    cout << "Looping over a copy: ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    } // prints 1 2 3
    cout << "\n";
    printqueue("k", k); // {1, 2, 3} k is untouched

    /*
    for a queue<pair<int, int>>, front() and back() give the pair itself:
    q.front().first
    q.front().second
    (no arrow needed, you are not using an iterator)
    */

    /*
    complexity: push, emplace, pop, front, back, size, empty, swap are all O(1)
    copying a queue is O(n)
    */

    cout << "\n";
    return 0;
}