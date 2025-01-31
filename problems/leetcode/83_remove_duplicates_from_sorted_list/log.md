# 83. Remove Duplicates from Sorted List

- Easy may not be that easy when your head is all mumbo jumbo.

- I've missed the `curr->next != nullptr` part, that lead to segmentation fault errors.

- It's possible to just reorganize the nodes and pass the problem leaving dangling
  nodes with no next pointers. It's better to delete them to avoid leaks. To do this
  -in C++- is much easier that what I expected: `delete some_node`.

- The worst case is a linked list where all values are repeated, i.e., `x -> x -> ... -> x`.
  The time complexity is $O(n)$ and memory complexity is $O(1)$.
