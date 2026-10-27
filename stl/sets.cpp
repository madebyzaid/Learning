#include <bits/stdc++.h>
#include "mylib/utils.h"
using namespace std;

int main() {
    // set = unique elements, always stored in sorted order (ascending by default)
    // you don't choose the position, insert(value) puts it in the right spot
    // no push_back, no s[i], no begin() + n, and elements are read-only
    // insert, erase, find, count, lower_bound, upper_bound are all O(log n)

    // CREATION

    // general syntax: set<TYPE> name;  or  set<TYPE, COMPARATOR> name;
    // COMPARATOR is optional, default is less<TYPE> (ascending)

    set<int> a; // empty set
    printset("a", a);

    set<int> b = {5, 1, 3, 1}; // sorted, duplicate dropped
    printset("b", b); // {1, 3, 5}

    set<int> c {5, 1, 3, 1};
    printset("c", c); // {1, 3, 5}

    set<int, greater<int>> d = {5, 1, 3}; // descending order
    printset("d", d); // {5, 3, 1}

    // there is no (n, value) constructor, so set<int> s(5, 7); is NOT "5 copies of 7"

    vector<int> v = {4, 2, 4, 9, 2};
    set<int> e(v.begin(), v.end()); // sorted unique elements of v
    printset("e", e); // {2, 4, 9}

    set<int> f(b); // copy of b
    printset("f", f);

    set<int> g = b; // copy of b
    printset("g", g);

    set<pair<int, int>> m; // set of pairs, sorted by first, then second

    cout << "\n";

    // METHODS

    // Inserting

    set<int> h = {10, 20, 30, 40};
    printset("h", h);

    // h.insert(value);
    h.insert(25);
    printset("h", h); // {10, 20, 25, 30, 40}

    h.insert(20); // 20 is already there, nothing changes
    printset("h", h); // {10, 20, 25, 30, 40}

    // h.insert({v1, v2, ...});
    h.insert({5, 50, 50});
    printset("h", h); // {5, 10, 20, 25, 30, 40, 50}

    // h.insert(first, last); iterators from a DIFFERENT container
    set<int> other = {1, 2, 3};
    h.insert(other.begin(), other.end());
    printset("h", h); // {1, 2, 3, 5, 10, 20, 25, 30, 40, 50}

    /* insert returns a pair<iterator, bool>
    the iterator points at the element (new or already there)
    the bool says whether a NEW element was added */
    auto [it1, added1] = h.insert(60);
    cout << *it1 << " " << added1 << "\n"; // 60 1
    auto [it2, added2] = h.insert(20);
    cout << *it2 << " " << added2 << "\n"; // 20 0

    m.insert({2, 5}); // adds an already constructed pair
    m.emplace(1, 9); // hands 1 and 9 to the pair constructor
    m.emplace(2, 3);
    m.emplace(1, 9); // duplicate pair, ignored
    // m = {{1, 9}, {2, 3}, {2, 5}}
    cout << "m = ";
    for (auto x : m) {
        cout << "{" << x.first << ", " << x.second << "} ";
    }
    cout << "\n\n";

    // Smallest, largest, size, empty

    set<int> k = {10, 20, 30, 40};
    printset("k", k);

    // there is no front() or back()
    cout << "smallest = " << *k.begin() << "\n"; // 10
    cout << "largest = " << *k.rbegin() << "\n"; // 40
    cout << "k.size() = " << k.size() << "\n"; // 4
    cout << "k.empty() = " << k.empty() << "\n"; // 0

    cout << "\n";

    // Searching

    // k.find(value); returns an iterator to the element, or k.end() if absent
    cout << "*k.find(30) = " << *k.find(30) << "\n"; // 30
    cout << "k.find(99) == k.end() is " << (k.find(99) == k.end()) << "\n"; // 1
    if (k.find(20) != k.end()) {
        cout << "20 is in the set\n";
    }
    // always check != k.end() before dereferencing, *k.end() is undefined

    // k.count(value); 0 or 1 for a set
    cout << "k.count(30) = " << k.count(30) << "\n"; // 1
    cout << "k.count(99) = " << k.count(99) << "\n"; // 0

    cout << "\n";

    // lower_bound / upper_bound
    // k.lower_bound(x); iterator to the first element >= x
    // k.upper_bound(x); iterator to the first element >  x
    // k = {10, 20, 30, 40}
    cout << *k.lower_bound(20) << "\n"; // 20
    cout << *k.upper_bound(20) << "\n"; // 30
    cout << *k.lower_bound(25) << "\n"; // 30
    cout << *k.upper_bound(25) << "\n"; // 30
    cout << *k.lower_bound(40) << "\n"; // 40
    cout << (k.upper_bound(40) == k.end()) << "\n"; // 1, nothing is > 40
    cout << (k.lower_bound(50) == k.end()) << "\n"; // 1, nothing is >= 50
    // if the result is k.end(), there is no such element, don't dereference it
    // use the member k.lower_bound(x), NOT lower_bound(k.begin(), k.end(), x) which is O(n)

    cout << "\n";

    // Erasing

    set<int> n = {10, 20, 30, 40, 50, 60};
    printset("n", n);

    // n.erase(value); returns how many were removed (0 or 1)
    cout << n.erase(30) << "\n"; // 1
    printset("n", n); // {10, 20, 40, 50, 60}
    cout << n.erase(99) << "\n"; // 0, not present, nothing happens

    // n.erase(iterator); returns an iterator to the next element
    auto it = n.erase(n.begin());
    cout << "next of erased element = " << *it << "\n"; // 20
    printset("n", n); // {20, 40, 50, 60}

    // n.erase(first, last); last is NOT erased
    n.erase(next(n.begin(), 1), next(n.begin(), 3)); // removes 40 and 50
    printset("n", n); // {20, 60}

    // n.clear()
    n.clear();
    printset("n", n); // {}

    // n.erase(n.find(x)) is only safe if x is present, because erasing end() is undefined
    // n.erase(x) is safe either way

    // erasing while looping, use the iterator that erase returns
    set<int> r = {1, 2, 3, 4, 5, 6};
    for (auto t = r.begin(); t != r.end();) {
        if (*t % 2 == 0) {
            t = r.erase(t);
        } else {
            t++;
        }
    }
    printset("r", r); // {1, 3, 5}

    cout << "\n";

    // Others

    // swap(p, q); or swap(q, p); or p.swap(q); or q.swap(p);
    set<int> p = {1, 2}, q = {7, 8, 9};
    swap(p, q);
    printset("p", p); // {7, 8, 9}
    printset("q", q); // {1, 2}

    // you cannot modify an element in place
    // to change a value, erase it and insert the new one

    cout << "\n";

    // ITERATORS
    /*
    s.begin(): smallest element
    s.end(): one position past the largest element
    s.rbegin(): largest element (reverse iterator)
    s.rend(): one position before the smallest element
    */

    /*
    set iterators are bidirectional, like list: ++ and -- work, but s.begin() + 2 does NOT
    use next(s.begin(), 2) and prev(s.end())
    elements are read-only through an iterator, *it = 5 won't compile
    erase invalidates only the erased iterator, all others stay valid
    */

    // do not dereference s.end() and s.rend()

    // LOOPING
    set<int> u = {50, 10, 40, 20, 30};
    printset("u", u); // {10, 20, 30, 40, 50}, always sorted

    // iterator loop
    // auto lets compiler deduce the type of t
    // here type of t is set<int>::iterator
    cout << "Tripling the elements: ";
    for (auto t = u.begin(); t != u.end(); t++) {
        cout << *t * 3 << " ";
    }
    cout << "\n";
    printset("u", u);

    // range-for
    // x is a copy
    cout << "Quadrupling the elements: ";
    for (auto x : u) {
        x = x * 4;
        cout << x << " ";
    }
    cout << "\n";
    printset("u", u); // unchanged

    // range-for by const reference, no copy, can't modify
    // for (auto &x : u) { x = x * 5; } won't compile, elements are const
    cout << "Reading by reference: ";
    for (const auto &x : u) {
        cout << x << " ";
    }
    cout << "\n";

    // reverse loop, largest to smallest
    cout << "Reverse order: ";
    for (auto t = u.rbegin(); t != u.rend(); t++) {
        cout << *t << " ";
    }
    cout << "\n";

    /*
    for a set<pair<int, int>>, access members through an
    iterator with an arrow:
    it -> first (shorthand for (*it).first)
    it -> second (shorthand for (*it).second)
    */

    /*
    complexity:
    insert, emplace, erase (value or iterator), find, count,
    lower_bound, upper_bound: O(log n)
    begin, end, rbegin, size, empty, swap: O(1)
    erase(first, last), clear: O(number of elements removed)
    next(it, k): O(k)
    looping over the whole set: O(n)
    */

    cout << "\n";
    return 0;
}