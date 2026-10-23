#include <bits/stdc++.h>
#include <utils.h>
using namespace std;

int main() {
    // CREATION
    list<int> a;
    printlist("a", a);

    list<int> b = {1, 2, 3, 4, 5};
    printlist("b", b);

    list<int> c(3); // c = {0, 0, 0}
    printlist("c", c);

    list<int> d(3, 6); // d = {6, 6, 6}
    printlist("d", d);

    list<int> e(b); // e = copy of b
    printlist("e", e);

    list<int> f = a; // f = copy of a
    printlist("f", f);

    cout << "\n";

    // METHODS
    list<int> g = {10, 20, 30};
    printlist("g", g);

    g.push_front(0); g.push_back(40);
    printlist("g", g);

    g.emplace_front(-10); g.emplace_back(50);
    printlist("g", g);
    
    g.pop_front(); g.pop_back();
    printlist("g", g);

    cout << "\n";

    // note: lists aren't random access so they're not indexed
    // auto t = g.begin(); is valid, and t points to 0
    // auto t = g.begin() + 2; is NOT valid
    // you gotta do auto t = next(g.begin(), 2), and t points to 20
    // similarly we have prev(g.end, 3) and stuff
    // but you can do ++ or --, it works

    auto t = next(g.begin(), 2);
    cout << "next(g.begin(), 2) is an iterator which points to  " << *t << "\n";
    cout << "g.begin()++ returns an iterator which points to " << *g.begin()++ << "\n";
    cout << "++g.begin() returns an iterator which points to " << *++g.begin() << "\n";

    cout << "\n";
    
    // ACCESSING
    list<int> h = {76, 98, 65, 48};
    printlist("h", h);

    cout << "h.front() = " << h.front() << "\n";
    cout << "h.back() = " << h.back() << "\n";
    // no such thing as h[i] or h.at[i]
    cout << "h.size() = " << h.size() << "\n"; 
    cout << "h.empty() = " << h.empty() << "\n";

    cout << "\n";

    // MODIFYING
    list<int> i = {1, 2, 3};
    i.clear(); // i = {}
    
    list<int> j = {1, 2, 3};
    printlist("j", j);

    // j.insert(iterator, value);
    j.insert(j.begin(), 99);
    printlist("j", j);

    // j.insert(iterator, count, value);
    j.insert(j.begin(), 3, 0);
    printlist("j", j);

    // j.insert(iterator, first, last);
    // right now g = {0, 10, 20, 30, 40}
    j.insert(next(j.begin(), 4), g.begin(), next(g.begin(), 3));
    printlist("j", j);

    cout << "\n";

    list<int> k = {99, 76, 2635, -587, 1, 48, 0, 666, 69, 8};
    printlist("k", k);

    // k.erase(iterator);
    k.erase(next(k.begin(), 3));
    printlist("k", k);

    // k.erase(first, last);
    k.erase(next(k.begin(), 3), next(k.begin(), 6));
    printlist("k", k);

    // k.pop_front();
    k.pop_front();
    printlist("k", k);

    // k.pop_back();
    k.pop_back();
    printlist("k", k);

    cout << "\n";

    // swap is also there

    // ITERATORS
    /*
    k.begin(): first element
    k.end(): one position past the last element
    k.rbegin(): last element
    k.rend(): one position before first element
    */

    /*
    insert and erase do NOT invalidate other iterators.
    Only iterators pointing at an erased element become invalid.
    So list is useful when you keep iterators and edit around them,
    but vector is usually faster in practice (contiguous memory).
    */

    // LOOPING
    list<int> l = {10, 20, 30, 40, 50};
    printlist("l", l);
    
    // iterator loop
    // auto lets compiler deduce the type of t
    // here type of t is list<int>::iterator
    cout << "Tripling the elements: ";
    for (auto t = l.begin(); t != l.end(); t++) {
        cout << *t * 3 << " ";
    }
    cout << "\n";
    printlist("l", l);

    // range-for
    // x is a copy
    cout << "Quadrupling the elements: ";
    for (auto x : l) {
        x = x * 4;
        cout << x << " "; 
    }
    cout << "\n";
    printlist("l", l);

    // range-for
    // x is a reference to an element in g
    cout << "Quintupling the elements: ";
    for (auto &x : l) {
        x = x * 5;
        cout << x << " "; // element in vector get quintupled
    }
    cout << "\n";
    printlist("l", l);

    cout << "\n";

    return 0;
}