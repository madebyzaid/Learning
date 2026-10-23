/*
COMPLEXITY (n = number of elements in the vector)
push_back / emplace_back      amortized O(1) (occasionally O(n) when it reallocates)
pop_back                      O(1)
a[i], a.at(i)                 O(1)
front, back, size, empty      O(1)
insert(it, x)                 O(n): shifts everything after it (O(1) at the end)
insert(it, count, x)          O(n + count)
insert(it, first, last)       O(n + k), k = length of the range
erase(it)                     O(n): shifts everything after it
erase(first, last)            O(n)
clear                         O(n): destroys every element
swap                          O(1): swaps internals, no copying
vector<int> v(n) / v(n, x)    O(n)
copy constructor              O(n)
begin, end, rbegin, rend      O(1)
any full loop                 O(n)