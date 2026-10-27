# Vector vs Deque vs List

## Same in all three
Creation patterns (including `(5, 7)` vs `{5, 7}`), `push_back`, `pop_back`, `emplace_back`, `front()`, `back()`, `size()`, `empty()`, `clear()`, `swap()`, `insert` (goes before the iterator), `erase` (returns the next iterator), range-for loops, `begin()`/`end()`/`rbegin()`/`rend()`. All have O(1) `size()` and O(1) `push_back`/`pop_back`.

## Differences

| | Vector | Deque | List |
|---|---|---|---|
| Structure | one contiguous block | chunks of memory, not one block | doubly linked nodes |
| `push_front`, `pop_front`, `emplace_front` | no | yes, O(1) | yes, O(1) |
| `v[i]`, `at(i)` | yes, O(1) | yes, O(1) | **no** |
| `begin() + n` | yes | yes | **no**, use `next(it, n)` |
| Iterator type | random access | random access | bidirectional (only `++` and `--`) |
| Reach position `i` | O(1) | O(1) | O(n) |
| `insert`/`erase` at the front | O(n) | O(1) | O(1) |
| `insert`/`erase` in the middle | O(n), elements shift | O(n), elements shift | O(1) once you hold the iterator |
| `insert`/`erase` at the end | O(1) | O(1) | O(1) |
| After `insert`/`erase`, are old iterators valid? | invalid from that point onward; all of them if it reallocates | treat all as invalid | **all stay valid** except the erased one |
| `capacity`, `reserve`, `data()` | yes | no | no |
| `std::sort(begin, end)` works? | yes | yes | **no**, use `l.sort()` |
| List-only member functions (`splice`, `merge`, `unique`, `remove`, `reverse`, `sort`) | no | no | yes |
| Memory overhead | lowest | medium | highest (two pointers per element) |
| Speed in practice | fastest (cache friendly) | close behind | slowest |
| Typical use | default choice | need both ends plus indexing | need stable iterators or frequent middle inserts |

## One-line summary
- **Vector:** fastest default, but no cheap front operations.
- **Deque:** vector plus cheap `push_front` and `pop_front`.
- **List:** cheap front operations and stable iterators, but no indexing, no `+ n`, no `std::sort`.