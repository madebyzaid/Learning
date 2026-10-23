#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

int main() {
    // CREATION

    vector<int> v; // empty vector
    printvector("v", v);

    vector<int> w = {1, 2, 3, 4, 5, 6};
    printvector("w", w);

    vector<int> x {1, 2, 3, 4, 5, 6};
    printvector("x", x);

    vector<int> y(4);
    printvector("y", y);

    vector<int> z(3, 7);
    printvector("z", z);

    vector<int> p(w); // copy of w
    printvector("p", p);

    vector<int> q = x; // copy of x
    printvector("q", q);

    vector<int> r(w.begin() + 1, w.begin() + 5); // {2, 3, 4, 5}
    printvector("r", r);

    cout << "\n";

    // METHODS

    // Adding at the back

    v.push_back(40); // {40}
    v.emplace_back(50); // {40, 50}

    vector<pair<int, int>> m;

    m.push_back({1, 2}); // adds an already constructed object
    m.emplace_back(2, 3); // hands to the pair constructor then adds

    // m = {{1, 2}, {2, 3}}
    
    /*
    in this case vector m has pair<int, int> elements so emplace_back
    hands the arguments to the pair<int, int> constructor

    so emplace_back constructs the arguments into whatever the vector stores

    m.emplace_back({4, 5}); won't work because {4, 5} is a single
    argument that can't be constructed into pair<int, int> type.
    */

    vector<int> a = {10, 29, 13, 82, 26, 19, 75};
    printvector("a", a);
    cout << "\n";

    // Accessing elements

    cout << "a[2] = " << a[2] << "\n"; 
    cout << "a.at(2) = " << a.at(2) << "\n";
    cout << "a.front() = " << a.front() << "\n";
    cout << "a.back() = " << a.back() << "\n";
    cout << "a.size() = " << a.size() << "\n";
    cout << "a.empty() = " << a.empty() << "\n\n";

    // Inserting elements

    // a.insert(iterator, value);
    a.insert(a.begin(), 999);
    printvector("a", a);

    // a.insert(iterator, count, value);
    a.insert(a.begin() + 2, 5, 555);
    printvector("a", a);

    // a.insert(iterator, first, last)
    // first & last are iterators can be from any container
    vector<int> b = {1000, -68, 98, 1, 44, 765, 12, 7777};
    a.insert(a.begin(), b.begin() + 2, b.begin() + 8);
    // (b.begin() + 2, b.begin() + 8) is a slice of b
    printvector("a", a);

    // Erasing elements

    // a.erase(iterator);
    a.erase(a.begin() + 2);
    printvector("a", a);

    /* note: a.erase(iterator) makes the iterator invalid
    but returns an iterator pointing to the element next to
    the removed element */
    cout << "element to be erased = " << *(a.begin() + 16) << "\n";
    cout << "next of erased element = " << *a.erase(a.begin() + 16) << "\n";
    printvector("a", a);

    // a.erase(first, last)
    a.erase(a.begin(), a.begin() + 7);
    printvector("a", a);

    // a.pop_back()
    a.pop_back();
    printvector("a", a);

    // a.clear()
    a.clear();
    printvector("a", a);


    cout << "\n";

    // Others

    // swap(e, d); or swap(d, e); or e.swap(d); or d.swap(e);
    vector<int> d = {1, 2}, e = {7, 8, 9};
    swap(e, d);
    printvector("d", d);
    printvector("e", e);

    cout << "\n";

    // ITERATORS
    /*
    f.begin(): first element (forward iterator)
    f.end(): one position past last element
    f.rbegin(): last element (reverse iterator)
    f.rend(): one position before the first element
    */

    /*
    push_back / insert can reallocate, which invalidates ALL iterators.
    erase invalidates iterators at and after the erased position.
    Re-fetch the iterator after modifying the vector.
    */

    // do not dereference f.end() and f.rend()

    vector<int> f = {28, 94, 26, 75, 64, 39, 70, 58};
    printvector("f", f);
    cout << "first element = " << *f.begin() << "\n";
    cout << "last element = " << *(f.end() -1) << "\n";
    cout << "2nd element from last = " << *(f.rbegin() + 1) << "\n";

    cout << "\n";

    // LOOPING
    vector<int> g = {10, 20, 30, 40, 50};
    printvector("g", g);

    // index loop
    cout << "Doubling the elements: ";
    for (uint i = 0; i < g.size(); i++) {
        cout << g[i] * 2 << " ";
    }
    cout << "\n";
    printvector("g", g);
    
    // iterator loop
    // auto lets compiler deduce the type of t
    // here type of t is vector<int>::iterator
    cout << "Tripling the elements: ";
    for (auto t = g.begin(); t != g.end(); t++) {
        cout << *t * 3 << " ";
    }
    cout << "\n";
    printvector("g", g);

    // range-for
    // x is a copy
    cout << "Quadrupling the elements: ";
    for (auto x : g) {
        x = x * 4;
        cout << x << " "; 
    }
    cout << "\n";
    printvector("g", g);

    // range-for
    // x is a reference to an element in g
    cout << "Quintupling the elements: ";
    for (auto &x : g) {
        x = x * 5;
        cout << x << " "; // element in vector get quintupled
    }
    cout << "\n";
    printvector("g", g);

    /*
    for a vector<pair<int, int>>, access members through an
    iterator with an arrow:
    it -> first (shorthand for (*it).first)
    it -> second (shorthand for (*it).second)
    */

    // swap is also there

    cout << "\n";
    return 0;
}