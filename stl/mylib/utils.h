#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <utility>

// Prints a single value. Pairs print as {a, b}, including nested ones.
template <typename T>
void printvalue(const T& x) {
    std::cout << x;
}

template <typename A, typename B>
void printvalue(const std::pair<A, B>& p) {
    std::cout << "{";
    printvalue(p.first);
    std::cout << ", ";
    printvalue(p.second);
    std::cout << "}";
}

// Prints any iterable container as: name = {1, 2, 3}
template <typename Container>
void printcontainer(const std::string& name, const Container& c) {
    std::cout << name << " = {";
    bool first = true;
    for (const auto& x : c) {
        if (!first) std::cout << ", ";
        printvalue(x);
        first = false;
    }
    std::cout << "}\n";
}

template <typename T>
void printvector(const std::string& name, const std::vector<T>& v) {
    printcontainer(name, v);
}

template <typename T>
void printlist(const std::string& name, const std::list<T>& l) {
    printcontainer(name, l);
}

template <typename A, typename B>
void printpair(const std::string& name, const std::pair<A, B>& p) {
    std::cout << name << " = ";
    printvalue(p);
    std::cout << "\n";
}

template <typename T>
void printdeque(const std::string& name, const std::deque<T>& d) {
    std::cout << name << " = {";
    for (size_t i = 0; i < d.size(); i++) {
        std::cout << d[i];
        if (i + 1 < d.size()) std::cout << ", ";
    }
    std::cout << "}\n";
}

template <typename T>
void printstack(const std::string& name, std::stack<T> s) {
    std::vector<T> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    std::cout << name << " = {";
    for (size_t i = v.size(); i > 0; i--) {
        std::cout << v[i - 1];
        if (i > 1) std::cout << ", ";
    }
    std::cout << "}\n";
}

#include <queue>

template <typename T>
void printqueue(const std::string& name, std::queue<T> q) {
    std::cout << name << " = {";
    while (!q.empty()) {
        std::cout << q.front();
        q.pop();
        if (!q.empty()) std::cout << ", ";
    }
    std::cout << "} (front is on the left)\n";
}

template <typename T, typename C, typename Cmp>
void printpq(const std::string& name, std::priority_queue<T, C, Cmp> pq) {
    std::cout << name << " = {";
    while (!pq.empty()) {
        std::cout << pq.top();
        pq.pop();
        if (!pq.empty()) std::cout << ", ";
    }
    std::cout << "} (in pop order, top first)\n";
}

#include <set>

template <typename T, typename Cmp>
void printset(const std::string& name, const std::set<T, Cmp>& s) {
    std::cout << name << " = {";
    bool is_first = true;
    for (const auto& x : s) {
        if (!is_first) std::cout << ", ";
        std::cout << x;
        is_first = false;
    }
    std::cout << "}\n";
}