#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
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