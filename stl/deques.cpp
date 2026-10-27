#include <bits/stdc++.h>
#include "mylib/utils.h"
using namespace std;

int main() {
    // deque = vector + push_front / pop_front / emplace_front
    // indexing d[i] and iterator + n both work, same as vector

    // CREATION

    deque<int> a; // empty deque
    printdeque("a", a);

    deque<int> b = {1, 2, 3, 4, 5, 6};
    printdeque("b", b);

    deque<int> c {1, 2, 3, 4, 5, 6};
    printdeque("c", c);

    deque<int> d(4); // d = {0, 0, 0, 0}
    printdeque("d", d);

    deque<int> e(3, 7); // e = {7, 7, 7}, parentheses mean 3 copies of 7
    printdeque("e", e);

    deque<int> f {3, 7}; // f = {3, 7}, braces mean the elements themselves
    printdeque("f", f);

    deque<int> g(b); // copy of b
    printdeque("g", g);

    deque<int> h = c; // copy of c
    printdeque("h", h);

    deque<int> i(b.begin() + 1, b.begin() + 5); // {2, 3, 4, 5}
    printdeque("i", i);

    cout << "\n";

    // METHODS

    // Adding and removing at both ends

    deque<int> j = {10, 20, 30};
    printdeque("j", j);

    j.push_back(40); // {10, 20, 30, 40}
    j.push_front(5); // {5, 10, 20, 30, 40}
    printdeque("j", j);

    j.emplace_back(50); // {5, 10, 20, 30, 40, 50}
    j.emplace_front(1); // {1, 5, 10, 20, 30, 40, 50}
    printdeque("j", j);

    j.pop_back(); // {1, 5, 10, 20, 30, 40}
    j.pop_front(); // {5, 10, 20, 30, 40}
    printdeque("j", j);

    deque<pair<int, int>> m;

    m.push_front({1, 2}); // adds an already constructed pair
    m.emplace_back(2, 3); // hands 2 and 3 to the pair constructor
    m.emplace_front(0, 9);

    // m = {{0, 9}, {1, 2}, {2, 3}}
    // m.emplace_front({4, 5}); won't work, same reason as emplace_back on a vector

    cout << "\n";

    // Accessing elements

    deque<int> k = {76, 98, 65, 48};
    printdeque("k", k);

    cout << "k[2] = " << k[2] << "\n"; // unlike list, indexing works
    cout << "k.at(2) = " << k.at(2) << "\n"; // at() throws if out of range, [] doesn't check
    cout << "k.front() = " << k.front() << "\n";
    cout << "k.back() = " << k.back() << "\n";
    cout << "k.size() = " << k.size() << "\n";
    cout << "k.empty() = " << k.empty() << "\n\n";

    // Inserting elements (always goes BEFORE the iterator)

    deque<int> p = {10, 29, 13, 82, 26, 19, 75};
    printdeque("p", p);

    // p.insert(iterator, value);
    p.insert(p.begin(), 999);
    printdeque("p", p); // {999, 10, 29, 13, 82, 26, 19, 75}

    // p.insert(iterator, count, value);
    p.insert(p.begin() + 2, 3, 555);
    printdeque("p", p); // {999, 10, 555, 555, 555, 29, 13, 82, 26, 19, 75}

    // p.insert(iterator, first, last);
    // first & last are iterators from a DIFFERENT container
    deque<int> q = {1000, -68, 98, 1, 44, 765};
    p.insert(p.begin(), q.begin() + 2, q.begin() + 5); // inserts {98, 1, 44}
    printdeque("p", p); // {98, 1, 44, 999, 10, 555, 555, 555, 29, 13, 82, 26, 19, 75}

    /* note: insert returns an iterator pointing to the first
    newly inserted element */
    cout << "inserted element = " << *p.insert(p.begin() + 3, 7) << "\n"; // 7
    p.erase(p.begin() + 3); // removes the 7 again
    printdeque("p", p);

    // Erasing elements

    // p.erase(iterator);
    p.erase(p.begin() + 2); // removes 44
    printdeque("p", p); // {98, 1, 999, 10, 555, 555, 555, 29, 13, 82, 26, 19, 75}

    /* note: p.erase(iterator) makes the iterator invalid
    but returns an iterator pointing to the element next to
    the removed element */
    cout << "element to be erased = " << *(p.begin() + 3) << "\n"; // 10
    cout << "next of erased element = " << *p.erase(p.begin() + 3) << "\n"; // 555
    printdeque("p", p); // {98, 1, 999, 555, 555, 555, 29, 13, 82, 26, 19, 75}

    // p.erase(first, last); last is NOT erased
    p.erase(p.begin(), p.begin() + 6); // removes the first 6 elements
    printdeque("p", p); // {29, 13, 82, 26, 19, 75}

    // p.pop_back() and p.pop_front()
    p.pop_back();
    p.pop_front();
    printdeque("p", p); // {13, 82, 26, 19}

    // p.clear()
    p.clear();
    printdeque("p", p);

    cout << "\n";

    // Others

    // swap(r, s); or swap(s, r); or r.swap(s); or s.swap(r);
    deque<int> r = {1, 2}, s = {7, 8, 9};
    swap(r, s);
    printdeque("r", r); // {7, 8, 9}
    printdeque("s", s); // {1, 2}

    cout << "\n";

    // ITERATORS
    /*
    t.begin(): first element (forward iterator)
    t.end(): one position past last element
    t.rbegin(): last element (reverse iterator)
    t.rend(): one position before the first element
    */

    /*
    insert / erase in the middle invalidate ALL iterators.
    push_front / push_back also invalidate iterators (references to
    elements stay valid). Re-fetch iterators after modifying the deque,
    or use the iterator returned by insert / erase.
    */

    // do not dereference t.end() and t.rend()

    deque<int> t = {28, 94, 26, 75, 64, 39, 70, 58};
    printdeque("t", t);
    cout << "first element = " << *t.begin() << "\n"; // 28
    cout << "last element = " << *(t.end() - 1) << "\n"; // 58
    cout << "2nd element from last = " << *(t.rbegin() + 1) << "\n"; // 70
    cout << "element at index 3 = " << *(t.begin() + 3) << "\n"; // 75, random access

    cout << "\n";

    // LOOPING
    deque<int> u = {10, 20, 30, 40, 50};
    printdeque("u", u);

    // index loop
    cout << "Doubling the elements: ";
    for (size_t x = 0; x < u.size(); x++) {
        cout << u[x] * 2 << " ";
    }
    cout << "\n";
    printdeque("u", u);

    // iterator loop
    // auto lets compiler deduce the type of w
    // here type of w is deque<int>::iterator
    cout << "Tripling the elements: ";
    for (auto w = u.begin(); w != u.end(); w++) {
        cout << *w * 3 << " ";
    }
    cout << "\n";
    printdeque("u", u);

    // range-for
    // x is a copy
    cout << "Quadrupling the elements: ";
    for (auto x : u) {
        x = x * 4;
        cout << x << " ";
    }
    cout << "\n";
    printdeque("u", u); // unchanged

    // range-for
    // x is a reference to an element in u
    cout << "Quintupling the elements: ";
    for (auto &x : u) {
        x = x * 5;
        cout << x << " "; // elements in the deque get quintupled
    }
    cout << "\n";
    printdeque("u", u);

    /*
    for a deque<pair<int, int>>, access members through an
    iterator with an arrow:
    it -> first (shorthand for (*it).first)
    it -> second (shorthand for (*it).second)
    */

    cout << "\n";
    return 0;
}